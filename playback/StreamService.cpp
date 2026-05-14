#include "playback/StreamService.h"

namespace cinevault::playback {

StreamDescriptor StreamService::describeFile(const std::filesystem::path& filePath) const {
    return {filePath, "application/octet-stream", 0};
}

}
