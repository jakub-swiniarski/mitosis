#include "Timer.hpp"

Timer::Timer(float c) : cooldown(c) {}

bool Timer::elapsed(void) {
    if(getElapsedTime().asSeconds() >= cooldown) {
        restart();
        return 1;
    }
    return 0;
}
