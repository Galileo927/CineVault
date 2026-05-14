#include "media_core/CompatibilityChecker.h"

#include <algorithm>

namespace {

std::string lower(std::string value) {
    std::ranges::transform(value, value.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return value;
}

}

namespace cinevault::media_core {

MediaCompatibility CompatibilityChecker::checkForBrowser(
    const std::string& container,
    const std::string& videoCodec,
    const std::string& audioCodec) const {
    const auto c = lower(container);
    const auto v = lower(videoCodec);
    const auto a = lower(audioCodec);

    const bool mp4Container = c == "mp4" || c == "mov" || c == "m4v";
    const bool h264Video = v == "h264" || v == "avc1";
    const bool aacAudio = a == "aac" || a == "mp4a";

    if (mp4Container && h264Video && aacAudio) {
        return {PlaybackMode::DirectPlay, "MP4/H.264/AAC can usually direct play in browsers."};
    }

    return {
        PlaybackMode::Unsupported,
        "Browser direct-play compatibility is not confirmed for this media combination."
    };
}

}
