#pragma once

#include <filesystem>
#include <string>

namespace cinevault::playback {

class DirectPlayService {
public:
    bool canDirectPlay(const std::string& container, const std::string& videoCodec, const std::string& audioCodec) const;
};

}
