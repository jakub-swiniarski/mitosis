#include <SFML/Window/Keyboard.hpp>

#include "Ball.hpp"
#include "InputProcessor.hpp"

InputProcessor::InputProcessor(Ball *p) {
    player = p;
}

void InputProcessor::update(float mod) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        player->move(0.f, -100.f * mod);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        player->move(0.f, 100.f * mod);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player->move(-100.f * mod, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player->move(100.f * mod, 0.f);
}
