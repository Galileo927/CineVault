#pragma once

#include <algorithm>

namespace cinevault::playback {

class ProgressTracker {
public:
    double percentage(double positionSeconds, double durationSeconds) const;
};

}
