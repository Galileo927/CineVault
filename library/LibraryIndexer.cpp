#include "library/LibraryIndexer.h"

namespace cinevault::library {

IndexResult LibraryIndexer::index(const std::filesystem::path& rootPath) const {
    return {scanner_.scan(rootPath)};
}

}
