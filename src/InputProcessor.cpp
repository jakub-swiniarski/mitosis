#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Ball.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

InputProcessor::InputProcessor(Ball *p, sf::WindowBase *w) {
    player = p;
    window = w;
}

void InputProcessor::update(void) {
    sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    float rotation = M_PI / 2.f - std::atan2(player->getPosition().x + player->getRadius() / 2.f - mouse.x, player->getPosition().y + player->getRadius() / 2.f - mouse.y);
    player->set_speed(-BALL_SPEED * cos(rotation), -BALL_SPEED * sin(rotation));
}
