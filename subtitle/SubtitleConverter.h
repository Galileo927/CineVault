#pragma once

#include <string>

namespace cinevault::subtitle {

class SubtitleConverter {
public:
    std::string srtToWebVtt(const std::string& srtText) const;
};

}
