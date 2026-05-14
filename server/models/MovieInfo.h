#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace cinevault::server::models {

struct MovieInfo {
    std::int64_t id = 0;
    std::int64_t libraryId = 0;
    std::string title;
    std::optional<std::string> originalTitle;
    std::optional<int> year;
    std::optional<std::string> overview;
    std::optional<std::string> posterPath;
    std::optional<std::string> backdropPath;
    std::string filePath;
    std::uintmax_t fileSize = 0;
    std::optional<double> duration;
    std::optional<std::string> container;
    std::optional<std::string> videoCodec;
    std::optional<std::string> audioCodec;
    std::optional<int> width;
    std::optional<int> height;
    std::optional<double> fps;
    std::optional<std::uint64_t> bitrate;
    std::string status = "indexed";
    bool isFavorite = false;
    bool isWatched = false;
};

}
