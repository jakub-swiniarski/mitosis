#include <random>

#include "AICell.hpp"

#include "config.hpp"

AICell::AICell(sf::Vector2f v) : Cell(v), timer(cfg::ai_cell::ai_cooldown) {};

void AICell::update(float mod) {
    if (timer.elapsed()) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> rand_rotation(0, 360);
        float rotation = rand_rotation(rng) * M_PI / 180.f;
        
        speed.x = cfg::cell::speed * cos(rotation);
        speed.y = cfg::cell::speed * sin(rotation);
    }

    Cell::update(mod);
}
