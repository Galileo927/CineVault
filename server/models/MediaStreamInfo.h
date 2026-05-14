#pragma once

#include <optional>
#include <string>

namespace cinevault::server::models {

enum class MediaStreamType {
    Video,
    Audio,
    Subtitle,
    Unknown
};

struct MediaStreamInfo {
    MediaStreamType type = MediaStreamType::Unknown;
    std::string codec;
    std::optional<std::string> language;
    std::optional<int> width;
    std::optional<int> height;
    std::optional<double> fps;
    std::optional<int> channels;
    std::optional<int> sampleRate;
    std::optional<std::string> title;
};

}
