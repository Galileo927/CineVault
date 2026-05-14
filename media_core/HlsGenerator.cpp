#include "media_core/HlsGenerator.h"

namespace cinevault::media_core {

std::optional<std::filesystem::path> HlsGenerator::startJob(const HlsJob&) const {
    return std::nullopt;
}

}
