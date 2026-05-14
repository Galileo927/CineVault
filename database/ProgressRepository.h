#pragma once

#include <optional>
#include <string>

#include "server/models/PlaybackProgress.h"

namespace cinevault::database {

class ProgressRepository {
public:
    std::optional<server::models::PlaybackProgress> find(const std::string& userId, std::int64_t movieId) const;
    void upsert(const server::models::PlaybackProgress& progress);
};

}
