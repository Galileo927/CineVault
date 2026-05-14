#include "media_core/FFmpegRunner.h"

namespace cinevault::media_core {

ProcessResult FFmpegRunner::run(const std::vector<std::string>&) const {
    return {
        127,
        "",
        "FFmpeg process execution is not wired in the skeleton."
    };
}

}
