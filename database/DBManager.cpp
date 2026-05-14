#include "database/DBManager.h"

#include <utility>

namespace cinevault::database {

DBManager::DBManager(std::filesystem::path databasePath)
    : databasePath_(std::move(databasePath)) {
}

const std::filesystem::path& DBManager::databasePath() const {
    return databasePath_;
}

}
