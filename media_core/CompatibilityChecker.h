#pragma once

#include <string>

namespace cinevault::media_core {

enum class PlaybackMode {
    DirectPlay,
    DirectStream,
    HlsTranscode,
    Unsupported
};

struct MediaCompatibility {
    PlaybackMode mode = PlaybackMode::Unsupported;
    std::string reason;
};

class CompatibilityChecker {
public:
    MediaCompatibility checkForBrowser(
        const std::string& container,
        const std::string& videoCodec,
        const std::string& audioCodec) const;
};

}
