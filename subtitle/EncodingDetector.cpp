#include "subtitle/EncodingDetector.h"

namespace cinevault::subtitle {

std::string EncodingDetector::detect(const std::filesystem::path&) const {
    return "utf-8";
}

}
