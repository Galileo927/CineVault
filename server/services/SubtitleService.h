#pragma once

#include <cstdint>
#include <vector>

#include "server/models/SubtitleInfo.h"

namespace cinevault::server::services {

class SubtitleService {
public:
    std::vector<models::SubtitleInfo> listSubtitles(std::int64_t movieId) const;
};

}
