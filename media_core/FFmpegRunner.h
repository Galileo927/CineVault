#pragma once

#include <string>
#include <vector>

namespace cinevault::media_core {

struct ProcessResult {
    int exitCode = 0;
    std::string stdoutText;
    std::string stderrText;
};

class FFmpegRunner {
public:
    ProcessResult run(const std::vector<std::string>& args) const;
};

}
