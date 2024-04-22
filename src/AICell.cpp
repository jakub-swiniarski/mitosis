#include <random>

#include "AICell.hpp"

#include "config.hpp"

void AICell::update(float mod) {
    if (clock.getElapsedTime().asSeconds() >= 2.f) {
        clock.restart();

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> rand_rotation(0, 360);
        float rotation = rand_rotation(rng) * M_PI / 180.f;
        
        speed.x = cfg::cell::speed * cos(rotation);
        speed.y = cfg::cell::speed * sin(rotation);
    }

    Cell::update(mod);
}
