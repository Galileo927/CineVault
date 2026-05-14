#pragma once

#include <optional>
#include <vector>

#include "server/models/MovieInfo.h"

namespace cinevault::database {

class MovieRepository {
public:
    std::vector<server::models::MovieInfo> listMovies() const;
    std::optional<server::models::MovieInfo> findById(std::int64_t movieId) const;
};

}
