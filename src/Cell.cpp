#include <random>

#include "Cell.hpp"

#include "config.hpp"

void Cell::update_ai(void) {
    float rotation = rand_rotation(rng) * M_PI / 180.0f;
    
    speed.x = cfg::cell::speed * cos(rotation);
    speed.y = cfg::cell::speed * sin(rotation);
}

Cell::Cell(sf::Vector2f position, bool is_ai)
    : is_ai(is_ai),
      speed(0.0f, 0.0f),
      timer(cfg::ai::cooldown),
      rng(std::random_device{}()),
      rand_rotation(0, 360) {
    setRadius(cfg::cell::radius);
    setFillColor(sf::Color::White);
    setPosition(position);
}

void Cell::grow(float radius) {
    setRadius(getRadius() + radius);
    move(-radius, -radius);
}

void Cell::set_speed(sf::Vector2f speed) {
    this->speed = speed;
}

void Cell::update(float mod) {
    move(speed.x * mod, speed.y * mod);

    if (is_ai && timer.elapsed())
        update_ai();
}
