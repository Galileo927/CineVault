#include "database/MovieRepository.h"

namespace cinevault::database {

std::vector<server::models::MovieInfo> MovieRepository::listMovies() const {
    return {};
}

std::optional<server::models::MovieInfo> MovieRepository::findById(std::int64_t) const {
    return std::nullopt;
}

}
