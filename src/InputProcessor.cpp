#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowBase.hpp>

#include "Cell.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

InputProcessor::InputProcessor(Cell *p, sf::WindowBase *w) : player(p), window(w) {}

void InputProcessor::update(void) const {
    sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    float rotation = M_PI / 2.f - std::atan2(window->getSize().x / 2.f - mouse.x, window->getSize().y / 2.f - mouse.y);
    player->set_speed(sf::Vector2f(-cfg::cell::speed * cos(rotation), -cfg::cell::speed * sin(rotation)));
}
