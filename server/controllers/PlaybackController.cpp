#include "server/controllers/PlaybackController.h"

#include <drogon/HttpResponse.h>
#include <json/json.h>

namespace {

drogon::HttpResponsePtr notImplemented(const std::string& code, const std::string& message) {
    Json::Value body;
    body["error"]["code"] = code;
    body["error"]["message"] = message;
    body["error"]["details"] = Json::objectValue;
    auto response = drogon::HttpResponse::newHttpJsonResponse(body);
    response->setStatusCode(drogon::k501NotImplemented);
    return response;
}

}

namespace cinevault::server::controllers {

void registerPlaybackRoutes(drogon::HttpAppFramework& app) {
    app.registerHandler(
        "/api/movies/{1}/stream",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "STREAM_NOT_IMPLEMENTED",
                "Direct Play streaming is scaffolded. Implement RangeRequestHandler and StreamService before enabling playback."));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/movies/{1}/playback",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string movieId) {
            Json::Value body;
            body["movie_id"] = movieId;
            body["position_seconds"] = 0;
            body["duration_seconds"] = 0;
            body["percentage"] = 0;
            body["is_finished"] = false;
            body["status"] = "scaffolded";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/movies/{1}/playback",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "PLAYBACK_PROGRESS_NOT_IMPLEMENTED",
                "Playback progress persistence is not connected yet."));
        },
        {drogon::Put});
}

}
