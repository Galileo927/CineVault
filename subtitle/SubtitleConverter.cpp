#include "subtitle/SubtitleConverter.h"

namespace cinevault::subtitle {

std::string SubtitleConverter::srtToWebVtt(const std::string& srtText) const {
    return "WEBVTT\n\n" + srtText;
}

}
