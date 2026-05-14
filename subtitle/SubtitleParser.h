#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace cinevault::subtitle {

struct SubtitleCue {
    double startSeconds = 0.0;
    double endSeconds = 0.0;
    std::string text;
};

class SubtitleParser {
public:
    std::vector<SubtitleCue> parseSrt(const std::filesystem::path& subtitlePath) const;
};

}
