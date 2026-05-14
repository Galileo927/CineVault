#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include "server/models/PlaybackProgress.h"

namespace cinevault::server::services {

class ProgressService {
public:
    std::optional<models::PlaybackProgress> getProgress(const std::string& userId, std::int64_t movieId) const;
    void saveProgress(const models::PlaybackProgress& progress);
};

}
