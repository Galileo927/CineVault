#include "library/MovieMatcher.h"

#include <algorithm>

namespace cinevault::library {

std::string MovieMatcher::titleFromFileName(const std::filesystem::path& filePath) const {
    auto title = filePath.stem().string();
    std::ranges::replace(title, '.', ' ');
    std::ranges::replace(title, '_', ' ');
    std::ranges::replace(title, '-', ' ');
    return title;
}

}
