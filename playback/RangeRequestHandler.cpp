#include "playback/RangeRequestHandler.h"

#include <charconv>
#include <string_view>

namespace {

std::optional<std::uint64_t> parseUnsigned(std::string_view value) {
    std::uint64_t result = 0;
    const auto* begin = value.data();
    const auto* end = begin + value.size();
    const auto parsed = std::from_chars(begin, end, result);
    if (parsed.ec != std::errc{} || parsed.ptr != end) {
        return std::nullopt;
    }
    return result;
}

}

namespace cinevault::playback {

ParsedRange RangeRequestHandler::parse(const std::string& rangeHeader) const {
    if (rangeHeader.empty()) {
        return {RangeParseStatus::Missing, std::nullopt, "No Range header was provided."};
    }

    constexpr std::string_view prefix = "bytes=";
    const std::string_view header(rangeHeader);
    if (!header.starts_with(prefix)) {
        return {RangeParseStatus::Invalid, std::nullopt, "Only byte ranges are supported."};
    }

    const auto spec = header.substr(prefix.size());
    if (spec.find(',') != std::string_view::npos) {
        return {RangeParseStatus::Invalid, std::nullopt, "Multiple ranges are not supported in the MVP."};
    }

    const auto dash = spec.find('-');
    if (dash == std::string_view::npos) {
        return {RangeParseStatus::Invalid, std::nullopt, "Range must contain a dash separator."};
    }

    const auto startText = spec.substr(0, dash);
    const auto endText = spec.substr(dash + 1);
    if (startText.empty()) {
        return {RangeParseStatus::Invalid, std::nullopt, "Suffix byte ranges require file size handling."};
    }

    auto start = parseUnsigned(startText);
    if (!start.has_value()) {
        return {RangeParseStatus::Invalid, std::nullopt, "Range start is not a valid byte offset."};
    }

    ByteRange range;
    range.start = *start;

    if (!endText.empty()) {
        auto end = parseUnsigned(endText);
        if (!end.has_value()) {
            return {RangeParseStatus::Invalid, std::nullopt, "Range end is not a valid byte offset."};
        }
        if (*end < range.start) {
            return {RangeParseStatus::Invalid, std::nullopt, "Range end is before range start."};
        }
        range.end = *end;
    }

    return {RangeParseStatus::Valid, range, "Range parsed."};
}

}
