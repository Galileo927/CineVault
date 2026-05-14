#include "server/services/ProgressService.h"

namespace cinevault::server::services {

std::optional<models::PlaybackProgress> ProgressService::getProgress(const std::string&, std::int64_t) const {
    return std::nullopt;
}

void ProgressService::saveProgress(const models::PlaybackProgress&) {
}

}
