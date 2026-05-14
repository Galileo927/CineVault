#include "server/controllers/LibraryController.h"

#include <drogon/HttpResponse.h>
#include <json/json.h>

namespace {

drogon::HttpResponsePtr errorResponse(
    const std::string& code,
    const std::string& message,
    drogon::HttpStatusCode status) {
    Json::Value body;
    body["error"]["code"] = code;
    body["error"]["message"] = message;
    body["error"]["details"] = Json::objectValue;
    auto response = drogon::HttpResponse::newHttpJsonResponse(body);
    response->setStatusCode(status);
    return response;
}

}

namespace cinevault::server::controllers {

void registerLibraryRoutes(drogon::HttpAppFramework& app) {
    app.registerHandler(
        "/api/libraries",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            Json::Value body;
            body["libraries"] = Json::arrayValue;
            body["status"] = "scaffolded";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});

    app.registerHandler(
        "/api/libraries",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            callback(errorResponse(
                "LIBRARY_CREATE_NOT_IMPLEMENTED",
                "Library creation is scaffolded. Wire this endpoint to LibraryService before use.",
                drogon::k501NotImplemented));
        },
        {drogon::Post});

    app.registerHandler(
        "/api/libraries/{1}/scan",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string libraryId) {
            Json::Value details;
            details["library_id"] = libraryId;
            Json::Value body;
            body["error"]["code"] = "LIBRARY_SCAN_NOT_IMPLEMENTED";
            body["error"]["message"] = "Library scanning is scaffolded. Implement LibraryIndexer before enabling scans.";
            body["error"]["details"] = details;
            auto response = drogon::HttpResponse::newHttpJsonResponse(body);
            response->setStatusCode(drogon::k501NotImplemented);
            callback(response);
        },
        {drogon::Post});

    app.registerHandler(
        "/api/libraries/{1}/scan-status",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback,
           std::string libraryId) {
            Json::Value body;
            body["library_id"] = libraryId;
            body["status"] = "idle";
            body["message"] = "Scan status storage is not connected yet.";
            callback(drogon::HttpResponse::newHttpJsonResponse(body));
        },
        {drogon::Get});
}

}
