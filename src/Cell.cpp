#include "Cell.hpp"

#include "config.hpp"

Cell::Cell(float x, float y) {
    setRadius(cfg::ball::radius);
    setFillColor(sf::Color::White);
    setPosition(x, y);

    speed_x = 0.f;
    speed_y = 0.f;
}

sf::Vector2f Cell::get_middle(void) const {
    sf::Vector2f middle(getPosition().x + getRadius(), getPosition().y + getRadius());
    return middle;
}

void Cell::grow(float radius) {
    setRadius(getRadius() + radius / 10.f);
    move(-radius / 10.f, -radius / 10.f);
}

void Cell::set_speed(float x, float y) {
    speed_x = x;
    speed_y = y;
}

void Cell::update(float mod) {
    move(speed_x * mod, speed_y * mod);
}
