#include "Cell.hpp"

#include "config.hpp"

Cell::Cell(sf::Vector2f v) {
    setRadius(cfg::cell::radius);
    setFillColor(sf::Color::White);
    setPosition(v.x, v.y);

    speed.x = 0.f;
    speed.y = 0.f;
}

void Cell::grow(float radius) {
    setRadius(getRadius() + radius / 10.f);
    move(-radius / 10.f, -radius / 10.f);
}

void Cell::set_speed(sf::Vector2f v) {
    speed.x = v.x;
    speed.y = v.y;
}

void Cell::update(float mod) {
    move(speed.x * mod, speed.y * mod);
}
