#include "playback/ProgressTracker.h"

namespace cinevault::playback {

double ProgressTracker::percentage(double positionSeconds, double durationSeconds) const {
    if (durationSeconds <= 0.0) {
        return 0.0;
    }
    return std::clamp((positionSeconds / durationSeconds) * 100.0, 0.0, 100.0);
}

}
