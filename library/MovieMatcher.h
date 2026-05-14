#pragma once

#include <filesystem>
#include <string>

namespace cinevault::library {

class MovieMatcher {
public:
    std::string titleFromFileName(const std::filesystem::path& filePath) const;
};

}
