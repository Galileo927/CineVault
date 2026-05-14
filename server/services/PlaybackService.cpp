#include "server/services/PlaybackService.h"

namespace cinevault::server::services {

std::optional<StreamTarget> PlaybackService::resolveStreamTarget(std::int64_t) const {
    return std::nullopt;
}

}
