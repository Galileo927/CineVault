#include "subtitle/SubtitleMatcher.h"

namespace cinevault::subtitle {

std::optional<std::filesystem::path> SubtitleMatcher::findSameNameSrt(const std::filesystem::path& moviePath) const {
    auto subtitlePath = moviePath;
    subtitlePath.replace_extension(".srt");

    std::error_code error;
    if (std::filesystem::exists(subtitlePath, error) && std::filesystem::is_regular_file(subtitlePath, error)) {
        return subtitlePath;
    }

    auto upperSubtitlePath = moviePath;
    upperSubtitlePath.replace_extension(".SRT");
    if (std::filesystem::exists(upperSubtitlePath, error) && std::filesystem::is_regular_file(upperSubtitlePath, error)) {
        return upperSubtitlePath;
    }

    return std::nullopt;
}

}
