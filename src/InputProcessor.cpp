#include <SFML/Window/Keyboard.hpp>

#include "Ball.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

InputProcessor::InputProcessor(Ball *p, sf::Window *w) {
    player = p;
    window = w;
}

void InputProcessor::update(float mod) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        player->move(0.f, -BALL_SPEED * mod);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        player->move(0.f, BALL_SPEED * mod);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player->move(-BALL_SPEED * mod, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player->move(BALL_SPEED * mod, 0.f);
}
