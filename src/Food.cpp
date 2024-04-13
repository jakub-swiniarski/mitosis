#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <random>

#include "Food.hpp"

#include "config.hpp"

Food::Food(float player_x, float player_y) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand(0, 360);
    float rotation = rand(rng) * M_PI / 180.f;
    float distance = std::sqrt(std::pow(0.5 * cfg::Window::WIDTH, 2) + std::pow(0.5 * cfg::Window::HEIGHT, 2));

    setRadius(cfg::Food::RADIUS);
    setFillColor(sf::Color::Blue);
    setPosition(player_x + distance * cos(rotation), player_y + distance * sin(rotation)); 
}
