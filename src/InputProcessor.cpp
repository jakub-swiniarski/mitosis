#include <cmath>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowBase.hpp>

#include "Cell.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

InputProcessor::InputProcessor(Cell* player, sf::WindowBase& window)
    : player(player),
      window(window) {}

void InputProcessor::update(void) const {
    if (player == nullptr)
        return;

    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    float rotation = M_PI / 2.f - std::atan2(window.getSize().x / 2.f - mouse.x, window.getSize().y / 2.f - mouse.y);
    player->set_speed(sf::Vector2f(-cfg::cell::speed * cos(rotation), -cfg::cell::speed * sin(rotation)));
}
