#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace cinevault::server::models {

struct SubtitleInfo {
    std::int64_t id = 0;
    std::int64_t movieId = 0;
    std::optional<std::string> language;
    std::string format;
    std::string filePath;
    bool isEmbedded = false;
    std::optional<std::string> encoding;
    std::optional<std::string> title;
};

}
