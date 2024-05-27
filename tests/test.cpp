#include <gtest/gtest.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "your_file.hpp"

TEST(ErabReleaseResponseTest, SerializeAndDeserialize) {
    // Создание объекта ErabReleaseResponse
    ErabReleaseResponse response;
    response.cp_ue_id = 1234;
    response.erab_release_id_list = { 1, 2, 3 };

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

    // Сериализация объекта
    rapidjson::Document config;
    response.serialize(config);

    // Преобразование в строку для сравнения
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    config.Accept(writer);
    std::string serializedResponse = buffer.GetString();

    // Десериализация объекта
    ErabReleaseResponse deserializedResponse;
    deserializedResponse.deserialize(config);

    // Проверка результата
    EXPECT_EQ(response.cp_ue_id, deserializedResponse.cp_ue_id);
    EXPECT_EQ(response.erab_release_id_list, deserializedResponse.erab_release_id_list);
    EXPECT_EQ(response.erab_failed_list.size(), deserializedResponse.erab_failed_list.size());

    for (size_t i = 0; i < response.erab_failed_list.size(); i++) {
        EXPECT_EQ(response.erab_failed_list[i].e_rab_id, deserializedResponse.erab_failed_list[i].e_rab_id);
        EXPECT_EQ(response.erab_failed_list[i].cause, deserializedResponse.erab_failed_list[i].cause);
        EXPECT_EQ(response.erab_failed_list[i].cause_value, deserializedResponse.erab_failed_list[i].cause_value);
    }
}


TEST(ErabReleaseResponseTest, FieldInitialization) {
    ErabReleaseResponse response;

    // Проверка cp_ue_id
    EXPECT_EQ(response.cp_ue_id, 0);

    // Проверка erab_release_id_list
    EXPECT_TRUE(response.erab_release_id_list.empty());

    // Проверка erab_failed_list
    EXPECT_TRUE(response.erab_failed_list.empty());

    // Заполнение полей
    response.cp_ue_id = 1234;
    response.erab_release_id_list = { 1, 2, 3 };

    ERadioAccessBearerCause erabCause1;