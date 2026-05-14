#pragma once

#include <filesystem>
#include <string>

namespace cinevault::playback {

struct StreamDescriptor {
    std::filesystem::path filePath;
    std::string mimeType;
    std::uintmax_t fileSize = 0;
};

class StreamService {
public:
    StreamDescriptor describeFile(const std::filesystem::path& filePath) const;
};

}
