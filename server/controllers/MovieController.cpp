#include "server/controllers/MovieController.h"

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

void registerMovieRoutes(drogon::HttpAppFramework& app) {
    app.registerHandler(
        "/api/movies",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            Json::Value body;
            body["movies"] = Json::arrayValue;
            body["status"] = "scaffolded";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/movies/{1}",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "MOVIE_DETAIL_NOT_IMPLEMENTED",
                "Movie detail storage is scaffolded but not connected yet."));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/movies/{1}",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "MOVIE_UPDATE_NOT_IMPLEMENTED",
                "Movie metadata updates are not implemented in the skeleton."));
        },
        {drogon::Patch});

    app.registerHandler(
        "/api/movies/{1}/favorite",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "FAVORITE_NOT_IMPLEMENTED",
                "Favorite state persistence is not connected yet."));
        },
        {drogon::Post});

    app.registerHandler(
        "/api/movies/{1}/favorite",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string) {
            callback(notImplemented(
                "FAVORITE_NOT_IMPLEMENTED",
                "Favorite state persistence is not connected yet."));
        },
        {drogon::Delete});
}

}
