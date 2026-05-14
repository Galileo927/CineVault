#pragma once

#include <filesystem>
#include <string>

namespace cinevault::subtitle {

class EncodingDetector {
public:
    std::string detect(const std::filesystem::path& filePath) const;
};

}
