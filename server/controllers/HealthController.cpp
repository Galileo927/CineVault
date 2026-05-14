#include "server/controllers/HealthController.h"

#include <drogon/HttpResponse.h>
#include <json/json.h>

namespace cinevault::server::controllers {

void registerHealthRoutes(drogon::HttpAppFramework& app) {
    app.registerHandler(
        "/api/health",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            Json::Value body;
            body["status"] = "ok";
            body["service"] = "cinevault";
            body["version"] = "0.1.0";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});
}

}
