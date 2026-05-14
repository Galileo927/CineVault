#pragma once

#include <filesystem>
#include <vector>

namespace cinevault::library {

class FileScanner {
public:
    std::vector<std::filesystem::path> scan(const std::filesystem::path& rootPath) const;

private:
    bool isVideoFile(const std::filesystem::path& filePath) const;
};

}
