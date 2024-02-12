#include "../../include/util/Timer.hpp"


th::Timer::Timer(
    const double duration_
) : duration(duration_),
    startTime(std::chrono::system_clock::now()),
    isRunning_(false) {
    
}


void th::Timer::start() {
    isRunning_ = true;
    startTime = std::chrono::system_clock::now();
}


bool th::Timer::tick() {
    const bool s = (
        isRunning_ && 
        (std::chrono::system_clock::now() - startTime) > duration
    );
    if (s) isRunning_ = false;    
    return s;
}


bool th::Timer::isRunning() {
    return isRunning_;
}


void th::Timer::stop() {
    isRunning_ = false;
}