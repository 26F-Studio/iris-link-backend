#include <controllers/api_v1_WsControllerTest.h>

using namespace api::v1;
using namespace std;

void WsControllerTest::handleNewMessage(
    const WebSocketConnectionPtr& wsConnPtr,
    string&& message,
    const WebSocketMessageType& type
) {
    // write your application logic here
}

void WsControllerTest::handleNewConnection(const HttpRequestPtr& req, const WebSocketConnectionPtr& wsConnPtr) {
    // write your application logic here
}

void WsControllerTest::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr) {
    // write your application logic here
}
