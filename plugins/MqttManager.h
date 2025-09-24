#pragma once

#include <drogon/plugins/Plugin.h>
#include <mqtt/async_client.h>

namespace plugins {
    class MqttManager final : public drogon::Plugin<MqttManager> {
    public:
        MqttManager() = default;

        void initAndStart(const Json::Value& config) override;

        void shutdown() override;

    private:
        std::unique_ptr<mqtt::async_client> _client;
    };
}
