#include "database/SubtitleRepository.h"

namespace cinevault::database {

std::vector<server::models::SubtitleInfo> SubtitleRepository::listByMovieId(std::int64_t) const {
    return {};
}

}
