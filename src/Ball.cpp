#include <SFML/Graphics/Color.hpp>

#include "Ball.hpp"

#include "config.hpp"

Ball::Ball(float x, float y) {
    setRadius(cfg::ball::RADIUS);
    setFillColor(sf::Color::White);
    setPosition(x, y);

    speed_x = 0.f;
    speed_y = 0.f;
}

sf::Vector2f Ball::get_middle(void) {
    sf::Vector2f middle(getPosition().x + getRadius(), getPosition().y + getRadius());
    return middle;
}

void Ball::grow(float radius) {
    setRadius(getRadius() + radius / 10.f);
    move(-radius / 10.f, -radius / 10.f);
}

void Ball::set_speed(float x, float y) {
    speed_x = x;
    speed_y = y;
}

void Ball::update(float mod) {
    move(speed_x * mod, speed_y * mod);
}
