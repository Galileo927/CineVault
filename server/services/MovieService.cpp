#include "server/services/MovieService.h"

namespace cinevault::server::services {

std::vector<models::MovieInfo> MovieService::listMovies() const {
    return {};
}

std::optional<models::MovieInfo> MovieService::findMovieById(std::int64_t) const {
    return std::nullopt;
}

}
