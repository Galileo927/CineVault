#include "server/controllers/SubtitleController.h"

#include <drogon/HttpResponse.h>
#include <json/json.h>

namespace cinevault::server::controllers {

void registerSubtitleRoutes(drogon::HttpAppFramework& app) {
    app.registerHandler(
        "/api/movies/{1}/subtitles",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string movieId) {
            Json::Value body;
            body["movie_id"] = movieId;
            body["subtitles"] = Json::arrayValue;
            body["status"] = "scaffolded";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/subtitles/{1}/content",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            Json::Value body;
            body["error"]["code"] = "SUBTITLE_CONTENT_NOT_IMPLEMENTED";
            body["error"]["message"] = "Subtitle file reading is scaffolded but not connected yet.";
            body["error"]["details"] = Json::objectValue;
            auto response = drogon::HttpResponse::newHttpJsonResponse(body);
            response->setStatusCode(drogon::k501NotImplemented);
            callback(response);
        },
        {drogon::Get});
}

}
