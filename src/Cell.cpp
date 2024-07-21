#include <random>

#include "Cell.hpp"

#include "config.hpp"

void Cell::update_ai(void) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand_rotation(0, 360);
    float rotation = rand_rotation(rng) * M_PI / 180.f;
    
    speed.x = cfg::cell::speed * cos(rotation);
    speed.y = cfg::cell::speed * sin(rotation);
}

Cell::Cell(sf::Vector2f position, bool is_ai)
    : is_ai(is_ai),
      speed(0.f, 0.f),
      timer(cfg::ai::cooldown) {
    setRadius(cfg::cell::radius);
    setFillColor(sf::Color::White);
    setPosition(position);
}

void Cell::grow(float radius) {
    setRadius(getRadius() + radius / 10.f);
    move(-radius / 10.f, -radius / 10.f);
}

void Cell::set_speed(sf::Vector2f speed) {
    this->speed = speed;
}

void Cell::update(float mod) {
    move(speed.x * mod, speed.y * mod);

    if (is_ai && timer.elapsed())
        update_ai();
}
