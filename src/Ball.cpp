#include <SFML/Graphics/Color.hpp>

#include "Ball.hpp"

Ball::Ball(float x, float y) {
    setRadius(20.f); /* TODO: avoid magic numbers, radius will change */
    setFillColor(sf::Color::White);
    setPosition(x, y);

    speed_x = 0.f;
    speed_y = 0.f;
}

void Ball::update(float mod) {
    move(speed_x * mod, speed_y * mod);
}
