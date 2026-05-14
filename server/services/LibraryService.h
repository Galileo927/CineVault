#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace cinevault::server::services {

struct LibrarySummary {
    int id = 0;
    std::string name;
    std::filesystem::path rootPath;
    std::string status = "idle";
};

class LibraryService {
public:
    std::vector<LibrarySummary> listLibraries() const;
};

}
