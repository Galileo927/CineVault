#pragma once

#include <filesystem>

namespace cinevault::database {

class DBManager {
public:
    explicit DBManager(std::filesystem::path databasePath);

    const std::filesystem::path& databasePath() const;

private:
    std::filesystem::path databasePath_;
};

}
