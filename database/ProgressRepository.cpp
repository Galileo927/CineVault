#include "database/ProgressRepository.h"

namespace cinevault::database {

std::optional<server::models::PlaybackProgress> ProgressRepository::find(const std::string&, std::int64_t) const {
    return std::nullopt;
}

void ProgressRepository::upsert(const server::models::PlaybackProgress&) {
}

}
