#pragma once

#include <filesystem>
#include <optional>
#include <string>

namespace cinevault::media_core {

struct ProbeResult {
    std::string container;
    std::string videoCodec;
    std::string audioCodec;
    int width = 0;
    int height = 0;
    double fps = 0.0;
    double durationSeconds = 0.0;
    std::uint64_t bitrate = 0;
};

class MediaProbe {
public:
    std::optional<ProbeResult> probe(const std::filesystem::path& filePath) const;
};

}
