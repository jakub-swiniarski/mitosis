#include "Timer.hpp"

Timer::Timer(float cooldown)
    : cooldown(cooldown) {}

bool Timer::elapsed(void) {
    if(getElapsedTime().asSeconds() >= cooldown) {
        restart();
        return 1;
    }
    return 0;
}
