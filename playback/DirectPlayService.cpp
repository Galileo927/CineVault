#include "playback/DirectPlayService.h"

#include "media_core/CompatibilityChecker.h"

namespace cinevault::playback {

bool DirectPlayService::canDirectPlay(
    const std::string& container,
    const std::string& videoCodec,
    const std::string& audioCodec) const {
    media_core::CompatibilityChecker checker;
    return checker.checkForBrowser(container, videoCodec, audioCodec).mode == media_core::PlaybackMode::DirectPlay;
}

}
