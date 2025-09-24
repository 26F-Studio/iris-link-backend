#pragma once

#include <drogon/plugins/Plugin.h>

namespace plugins {
    class Configurator final : public drogon::Plugin<Configurator> {
    public:
        Configurator() = default;

        void initAndStart(const Json::Value& config) override;

        void shutdown() override;
    };
}
