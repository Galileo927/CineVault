#pragma once

#include <filesystem>
#include <optional>

namespace cinevault::subtitle {

class SubtitleMatcher {
public:
    std::optional<std::filesystem::path> findSameNameSrt(const std::filesystem::path& moviePath) const;
};

}
