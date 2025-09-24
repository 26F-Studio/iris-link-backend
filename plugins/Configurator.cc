#include <plugins/Configurator.h>

using namespace drogon;
using namespace plugins;

void Configurator::initAndStart(const Json::Value& config) {
    LOG_INFO << "Configurator plugin started";
}

void Configurator::shutdown() {
    LOG_INFO << "Configurator plugin stopped";
}
