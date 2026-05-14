#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace cinevault::playback {

struct ByteRange {
    std::uint64_t start = 0;
    std::optional<std::uint64_t> end;
};

enum class RangeParseStatus {
    Missing,
    Valid,
    Invalid
};

struct ParsedRange {
    RangeParseStatus status = RangeParseStatus::Missing;
    std::optional<ByteRange> range;
    std::string message;
};

class RangeRequestHandler {
public:
    ParsedRange parse(const std::string& rangeHeader) const;
};

}
