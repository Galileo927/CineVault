#include <cstdlib>
#include <string>

#include <drogon/drogon.h>

#include "server/controllers/HealthController.h"
#include "server/controllers/LibraryController.h"
#include "server/controllers/MovieController.h"
#include "server/controllers/PlaybackController.h"
#include "server/controllers/SubtitleController.h"

int main(int argc, char* argv[]) {
    const char* envConfig = std::getenv("CINEVAULT_CONFIG");
    const std::string configPath = argc > 1
        ? argv[1]
        : (envConfig != nullptr ? envConfig : "config/config.example.json");

    auto& app = drogon::app();
    app.loadConfigFile(configPath);

    cinevault::server::controllers::registerHealthRoutes(app);
    cinevault::server::controllers::registerLibraryRoutes(app);
    cinevault::server::controllers::registerMovieRoutes(app);
    cinevault::server::controllers::registerPlaybackRoutes(app);
    cinevault::server::controllers::registerSubtitleRoutes(app);

    LOG_INFO << "Starting CineVault server with config: " << configPath;
    app.run();
    return 0;
}
