#pragma once

#include <filesystem>
#include <optional>

namespace cinevault::media_core {

struct HlsJob {
    std::filesystem::path sourcePath;
    std::filesystem::path outputDirectory;
};

class HlsGenerator {
public:
    std::optional<std::filesystem::path> startJob(const HlsJob& job) const;
};

}
