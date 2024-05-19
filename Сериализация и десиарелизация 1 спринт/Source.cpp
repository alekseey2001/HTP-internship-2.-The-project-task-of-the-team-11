#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>

using cu_ue_id_t = uint32_t;
using e_rab_id_t = uint8_t;
using ErabsId = std::vector<e_rab_id_t>;

enum class RrcCause
{
    CAUSE_NOTHING, /* No components present */
    CAUSE_RADIO_NETWORK,
    CAUSE_TRANSPORT,
    CAUSE_NAS,
    CAUSE_PROTOCOL,
    CAUSE_MISC,
    CAUSE_EXTENTION,
};
using rrc_cause_value_t = uint8_t;
struct ERadioAccessBearerCause
{
    e_rab_id_t e_rab_id; //!< Unique e_rab_id for the UE

    RrcCause cause;       //!< E-RAB fail cause group
    rrc_cause_value_t cause_value; //!< E-RAB fail specific cause value belongs this group
};

using ErabsToFail = std::vector<ERadioAccessBearerCause>;

struct ErabReleaseResponse
{
    cu_ue_id_t cp_ue_id;
    ErabsId erab_release_id_list;
    ErabsToFail erab_failed_list;

    void serialize(rapidjson::Document& config) {
        config.SetObject();
        rapidjson::Document::AllocatorType& allocator = config.GetAllocator();

        config.AddMember("cp_ue_id", cp_ue_id, allocator);

        rapidjson::Value releaseList(rapidjson::kArrayType);
        for (const auto& id : erab_release_id_list) {
            rapidjson::Value erabId;
            erabId.SetInt(id);
            releaseList.PushBack(erabId, allocator);
        }
        config.AddMember("erab_release_id_list", releaseList, allocator);

        rapidjson::Value failedList(rapidjson::kArrayType);
        for (const auto& item : erab_failed_list) {
            rapidjson::Value erabToFail(rapidjson::kObjectType);
            erabToFail.AddMember("id", item.e_rab_id, allocator);
            erabToFail.AddMember("cause", static_cast<int>(item.cause), allocator);
            failedList.PushBack(erabToFail, allocator);
        }
        config.AddMember("erab_failed_list", failedList, allocator);
    }

    void deserialize(const rapidjson::Document& config) {
        cp_ue_id = config["cp_ue_id"].GetInt();

        const rapidjson::Value& releaseList = config["erab_release_id_list"];
        for (rapidjson::SizeType i = 0; i < releaseList.Size(); i++) {
            erab_release_id_list.push_back(static_cast<e_rab_id_t>(releaseList[i].GetInt()));
        }

        const rapidjson::Value& failedList = config["erab_failed_list"];
        for (rapidjson::SizeType i = 0; i < failedList.Size(); i++) {
            ERadioAccessBearerCause item;
            item.e_rab_id = failedList[i]["id"].GetUint();
            item.cause = static_cast<RrcCause>(failedList[i]["cause"].GetInt());
            erab_failed_list.push_back(item);
        }
    }
};

int main() {
    ErabReleaseResponse response;
    // Заполнение cp_ue_id
    response.cp_ue_id = 1234;

    // Заполнение erab_release_id_list
    response.erab_release_id_list = { 1, 2, 3 };

    // Заполнение erab_failed_list
    ERadioAccessBearerCause erabCause1;
    erabCause1.e_rab_id = 1;
    erabCause1.cause = RrcCause::CAUSE_RADIO_NETWORK;
    erabCause1.cause_value = 10;

    ERadioAccessBearerCause erabCause2;
    erabCause2.e_rab_id = 2;
    erabCause2.cause = RrcCause::CAUSE_TRANSPORT;
    erabCause2.cause_value = 20;

    response.erab_failed_list.push_back(erabCause1);
    response.erab_failed_list.push_back(erabCause2);

    rapidjson::Document config;
    response.serialize(config);

    // Преобразование в строку для демонстрации
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    config.Accept(writer);
    std::cout << buffer.GetString() << std::endl;

    // Десериализация
    ErabReleaseResponse deserializedResponse;
    deserializedResponse.deserialize(config);

    return 0;
}
