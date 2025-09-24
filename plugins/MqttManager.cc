#include <plugins/MqttManager.h>

using namespace drogon;
using namespace plugins;
using namespace std;

void MqttManager::initAndStart(const Json::Value& config) {
    if (!(
        config["url"].isString() &&
        config["client_id"].isUInt() &&
        config["account"].isString() &&
        config["password"].isString() &&
        config["senderEmail"].isString() &&
        config["senderName"].isString()
    )) {
        LOG_ERROR << R"(Invalid config)";
        abort();
    }

    _client = make_unique<mqtt::async_client>(config["uri"].asString(), config["client_id"].asString());
    LOG_INFO << "MqttManager plugin started";
}

void MqttManager::shutdown() {
    LOG_INFO << "MqttManager plugin stopped";
}
