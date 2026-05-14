#include "media_core/MediaProbe.h"

namespace cinevault::media_core {

std::optional<ProbeResult> MediaProbe::probe(const std::filesystem::path&) const {
    return std::nullopt;
}

}
