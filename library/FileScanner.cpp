#include "library/FileScanner.h"

#include <algorithm>
#include <string>

namespace cinevault::library {

std::vector<std::filesystem::path> FileScanner::scan(const std::filesystem::path& rootPath) const {
    std::vector<std::filesystem::path> files;
    std::error_code error;

    if (!std::filesystem::exists(rootPath, error) || !std::filesystem::is_directory(rootPath, error)) {
        return files;
    }

    const auto options = std::filesystem::directory_options::skip_permission_denied;
    std::filesystem::recursive_directory_iterator iterator(rootPath, options, error);
    const std::filesystem::recursive_directory_iterator end;

    while (iterator != end) {
        const auto& entry = *iterator;
        if (entry.is_regular_file(error) && isVideoFile(entry.path())) {
            files.push_back(entry.path());
        }
        iterator.increment(error);
    }

    std::ranges::sort(files);
    return files;
}

bool FileScanner::isVideoFile(const std::filesystem::path& filePath) const {
    std::string extension = filePath.extension().string();
    std::ranges::transform(extension, extension.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });

    return extension == ".mp4"
        || extension == ".m4v"
        || extension == ".mov"
        || extension == ".mkv"
        || extension == ".avi"
        || extension == ".webm";
}

}
