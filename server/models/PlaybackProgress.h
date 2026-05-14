#pragma once

#include <cstdint>
#include <string>

namespace cinevault::server::models {

struct PlaybackProgress {
    std::int64_t id = 0;
    std::string userId = "default";
    std::int64_t movieId = 0;
    double positionSeconds = 0.0;
    double durationSeconds = 0.0;
    double percentage = 0.0;
    bool isFinished = false;
};

}
