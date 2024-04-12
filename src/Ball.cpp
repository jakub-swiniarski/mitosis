#include <SFML/Graphics/Color.hpp>

#include "Ball.hpp"

Ball::Ball(float x, float y) {
    setRadius(20.f); /* TODO: avoid magic numbers, radius will change */
    setFillColor(sf::Color::White);
    setPosition(x, y);

    speed_x = 0.f;
    speed_y = 0.f;
}

void Ball::set_speed(float x, float y) {
    speed_x = x;
    speed_y = y;
}

void Ball::update(float mod) {
    move(speed_x * mod, speed_y * mod);
}
