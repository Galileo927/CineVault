#pragma once

#include <filesystem>
#include <optional>
#include <string>

namespace cinevault::library {

struct LocalArtwork {
    std::optional<std::filesystem::path> posterPath;
    std::optional<std::filesystem::path> backdropPath;
};

class MetadataManager {
public:
    LocalArtwork findLocalArtwork(const std::filesystem::path& moviePath) const;
};

}
