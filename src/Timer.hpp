#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/System/Clock.hpp>

class Timer : private sf::Clock {
    float cooldown;

public:
    Timer(float cooldown);

    bool elapsed(void);
};

#endif // TIMER_HPP
