#include "../itti_structs/types.hpp"
#include "../libs/rapidjson/include/rapidjson/document.h"
#include "../libs/rapidjson/include/rapidjson/writer.h"
#include "../libs/rapidjson/include/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/include/rapidjson/prettywriter.h"
#include <iostream>

using namespace rapidjson;
using namespace vran::s1ap::lte;

// Барков Игорь 

// Для того чтобы собрать и запустить нужно исполнить buildPSR.sh

// Комментарии к коду
// Я не сделал проверок при десериализации
// с помощью методов HasMember() и IsType() потому что это сильно бы
// усложнило код и сделоло бы медленнее

// Короче алгоритм такой: есть документ - некий, какой-то класс который мы собираем как-бы под видом JSON-а
// и всё-таки это просто класс, который умеет переводить в строковый формат JSON-а, то что мы в него накадали как в JSON, 
// и соответственно считывать из строкового формата JSON-а к себе внутрь в Document и потом уже его мы переводим в плюсовую структуру

// Кратенько про устройство rapidjson

// SetObject() --> инициализация пустого JSON-а и как я понял всегда обязательно делать при создании Document
// GetAllocator() --> он требуется в методе AddMember() для формирования Document
// AddMember(ключ, значение, аллокатор) --> добавляет новую пару в Document
// rapidjson::Value --> это как я понял, абстракция над элементарной единицей JSON-а, 
// промежуточный слой между Document-ом и плюсовыми структурами данных,
// хочем добавить или считать, создать массив и т.д. будь добр пользоваться Value
// SizeType - это просто alias на unsigned int, ну по их код стайлу сделал


// И да, я в исходном файле types.hpp добавил к структуре методы и в этом файле их уже определил

void PathSwitchRequest::serialize(rapidjson::Document& config)
{
    // Инициализируем пустой Document
    config.SetObject();
    // Спрашиваем аллокатор, он требуется в методе AddMember() для формирования Document
    Document::AllocatorType& alloc = config.GetAllocator();
    // ДОбавляем в Document первые два поля, это простые типы
    // cp_ue_id
    config.AddMember("cp_ue_id", cp_ue_id, alloc);
    // src_mme_ue_s1ap_id
    config.AddMember("src_mme_ue_s1ap_id", src_mme_ue_s1ap_id, alloc);
    // erab_switch_list -->
    // Создаём Value, он нужен для формирования составных типов, в данном случае это массив структур
    Value erabSwitchList(kArrayType);
    // Проходимся циклом по всем внутренним структуркам
    for (const auto& erab : erab_switch_list) 
    {
        // Снова создаём Value так как это тоже не фундаментальный тип
        Value erabValue(kObjectType);
        // Повторяем процедуру с внутренним типом
        erabValue.AddMember("e_rab_id", erab.e_rab_id, alloc);
            // erab_switch_list.sgw_addr -->
            // Ещё внутренняя структура (^_^)
            Value sgwAddrValue(kObjectType);
            sgwAddrValue.AddMember("length", erab.sgw_addr.length, alloc);
            
            Value bufferArray(kArrayType);
            for (int i = 0; i < erab.sgw_addr.length; ++i) {
                bufferArray.PushBack(erab.sgw_addr.buffer[i], alloc);
            }
            sgwAddrValue.AddMember("buffer", bufferArray, alloc);
        erabValue.AddMember("sgw_addr", sgwAddrValue, alloc);
        erabValue.AddMember("sgw_teid", erab.sgw_teid, alloc);
        erabSwitchList.PushBack(erabValue, alloc);
    }
    config.AddMember("erab_switch_list", erabSwitchList, alloc);
    // security_capabilities -->
        // И ещё разок
        Value securityCapabilitiesValue(kObjectType);
        securityCapabilitiesValue.AddMember("encryption_algorithms", security_capabilities.encryption_algorithms, alloc);
        securityCapabilitiesValue.AddMember("integrity_algorithms", security_capabilities.integrity_algorithms, alloc);
    config.AddMember("security_capabilities", securityCapabilitiesValue, alloc);
}

void PathSwitchRequest::deserialize(const rapidjson::Document& config) 
{
    // cp_ue_id 
    // Так мы достаем целочисленное значение по ключу
    cp_ue_id = config["cp_ue_id"].GetUint();
    // src_mme_ue_s1ap_id 
    src_mme_ue_s1ap_id = config["src_mme_ue_s1ap_id"].GetUint();
    // erab_switch_list -->
    // Делаем ссылку на внутренний вектор структур, чтобы поудобнее было его прописывать дальше
    const Value& erabSwitchList = config["erab_switch_list"];
    // Рекомендация ChatGPT очистить вектор, если там вдруг что-то было
    erab_switch_list.clear();
    // Проходимся по всему вектору
    for (SizeType i = 0; i < erabSwitchList.Size(); ++i) 
    {
        // Создаём внутреннюю структуру по дефолту
        ERadioAccessBearerSwitchParameter erab;
        // Заполняем
        erab.e_rab_id = erabSwitchList[i]["e_rab_id"].GetUint();
            // erab_switch_list.sgw_addr -->
            erab.sgw_addr.length = erabSwitchList[i]["sgw_addr"]["length"].GetUint();
            const Value& bufferArray = erabSwitchList[i]["sgw_addr"]["buffer"];
            for (SizeType i = 0; i < bufferArray.Size(); ++i) 
            {
                erab.sgw_addr.buffer[i] = bufferArray[i].GetUint();
            }
        erab.sgw_teid = erabSwitchList[i]["sgw_teid"].GetUint();
        erab_switch_list.push_back(erab);
    }
    // security_capabilities -->
    const Value& sec_cap = config["security_capabilities"];
    security_capabilities.encryption_algorithms = sec_cap["encryption_algorithms"].GetUint();
    security_capabilities.integrity_algorithms = sec_cap["integrity_algorithms"].GetUint();
}

/* Памятка при работе с внутренними полями структуры
// Внутреннее устройство структуры

struct PathSwitchRequest
{
    cu_ue_id_t            cp_ue_id;
    uint32_t              src_mme_ue_s1ap_id;
    ErabsSwitchParameters erab_switch_list;
    SecurityCapabilities  security_capabilities;

};

using cu_ue_id_t = uint32_t;

using ErabsSwitchParameters = std::vector<ERadioAccessBearerSwitchParameter>;

struct ERadioAccessBearerSwitchParameter
{
    e_rab_id_t            e_rab_id; //!< Unique e_rab_id for the UE
    TransportLayerAddress sgw_addr; //!< The transport layer address for the IP packets
    teid_t                sgw_teid; //!< S-GW Tunnel endpoint identifier


};

using e_rab_id_t = uint8_t;

struct TransportLayerAddress // moved cplane
{
    uint8_t length;     //!< Address length
    uint8_t buffer[20]; //!< Buffer containing the addres in network byte order
};

using teid_t     = uint32_t;// Tunnel Endpoint Identifier

struct SecurityCapabilities
{
    uint16_t encryption_algorithms; //!< Encryption algorithms configuration
    uint16_t integrity_algorithms;  //!< Integrity algorithms configuration
};

*/

// Сравнение в отдельной функции, можно и оператор == было бы сделать, но решил не перегружать исходный файл

bool isEqual(const PathSwitchRequest& request1, const PathSwitchRequest& request2) {
    return (request1.cp_ue_id == request2.cp_ue_id) &&
           (request1.src_mme_ue_s1ap_id == request2.src_mme_ue_s1ap_id) &&
           (request1.erab_switch_list.size() == request2.erab_switch_list.size()) &&
           (request1.erab_switch_list[0].e_rab_id == request2.erab_switch_list[0].e_rab_id) &&
           (request1.erab_switch_list[0].sgw_addr.length == request2.erab_switch_list[0].sgw_addr.length) &&
           (std::memcmp(request1.erab_switch_list[0].sgw_addr.buffer, request2.erab_switch_list[0].sgw_addr.buffer, request1.erab_switch_list[0].sgw_addr.length) == 0) &&
           (request1.erab_switch_list[0].sgw_teid == request2.erab_switch_list[0].sgw_teid) &&
           (request1.security_capabilities.encryption_algorithms == request2.security_capabilities.encryption_algorithms) &&
           (request1.security_capabilities.integrity_algorithms == request2.security_capabilities.integrity_algorithms);
}

int main() {
    
    // Примерчик работы сер-ции и дес-ции
    PathSwitchRequest request;
    request.cp_ue_id = 1000-7;
    request.src_mme_ue_s1ap_id = 54321;

    ERadioAccessBearerSwitchParameter erab;
    erab.e_rab_id = 1;
    erab.sgw_addr.length = 4;
    erab.sgw_addr.buffer[0] = 127;
    erab.sgw_addr.buffer[1] = 0;
    erab.sgw_addr.buffer[2] = 0;
    erab.sgw_addr.buffer[3] = 1;
    erab.sgw_teid = 1128;
    request.erab_switch_list.push_back(erab);

    request.security_capabilities.encryption_algorithms = 6666;
    request.security_capabilities.integrity_algorithms = 7777;

    // Сериализуем структуру в JSON
    Document doc;
    request.serialize(doc);

    // Выводим JSON на экран, красивенько через PrettyWriter
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    // делает JSON из документа т.е. : Document -> JSON в строковом формате
    doc.Accept(writer);

    std::cout << "PathSwitchRequest в JSON-е: " << buffer.GetString() << std::endl;

    // Десериализуем JSON в новую структуру
    PathSwitchRequest request2;
    Document doc2;

    // Преобразует JSON строковый формат в Document. : JSON в строковом формате --> Document
    doc2.Parse(buffer.GetString());
    request2.deserialize(doc2);

    // Проверяем, что данные в новой структуре совпадают с исходными
    if (isEqual(request, request2)) {
        std::cout << "УСПЕХ!!! Сериализация и десериализация вернули PathSwitchRequest в исходное состояние." << std::endl;
    } else {
        std::cout << "ОШИБКА!!! Сериализация и десериализация не вернули PathSwitchRequest в исходное состояние." << std::endl;
    }

    return 0;

}
