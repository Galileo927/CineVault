#pragma once

#include <filesystem>
#include <optional>

namespace cinevault::server::services {

struct StreamTarget {
    std::filesystem::path filePath;
    std::string mimeType = "application/octet-stream";
};

class PlaybackService {
public:
    std::optional<StreamTarget> resolveStreamTarget(std::int64_t movieId) const;
};

}
