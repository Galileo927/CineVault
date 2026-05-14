#pragma once

#include <cstdint>
#include <vector>

#include "server/models/SubtitleInfo.h"

namespace cinevault::database {

class SubtitleRepository {
public:
    std::vector<server::models::SubtitleInfo> listByMovieId(std::int64_t movieId) const;
};

}
