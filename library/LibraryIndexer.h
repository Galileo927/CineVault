#pragma once

#include <filesystem>
#include <vector>

#include "library/FileScanner.h"

namespace cinevault::library {

struct IndexResult {
    std::vector<std::filesystem::path> discoveredFiles;
};

class LibraryIndexer {
public:
    IndexResult index(const std::filesystem::path& rootPath) const;

private:
    FileScanner scanner_;
};

}
