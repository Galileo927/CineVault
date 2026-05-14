#pragma once

#include <optional>
#include <string>
#include <vector>

#include "server/models/MovieInfo.h"

namespace cinevault::server::services {

class MovieService {
public:
    std::vector<models::MovieInfo> listMovies() const;
    std::optional<models::MovieInfo> findMovieById(std::int64_t movieId) const;
};

}
