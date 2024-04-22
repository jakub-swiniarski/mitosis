#include <SFML/Graphics/Color.hpp>
#include <random>

#include "Food.hpp"

#include "config.hpp"

Food::Food(sf::Vector2f player_pos) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand_rotation(0, 360);
    std::uniform_int_distribution<std::mt19937::result_type> rand_rgb(0, 255);
    float rotation = rand_rotation(rng) * M_PI / 180.f;
    float distance = std::sqrt(std::pow(0.5 * cfg::window::width, 2) + std::pow(0.5 * cfg::window::height, 2)) + 5.f * cfg::food::radius;

    setRadius(cfg::food::radius);
    setFillColor(sf::Color(rand_rgb(rng), rand_rgb(rng), rand_rgb(rng)));
    setPosition(player_pos.x + distance * cos(rotation), player_pos.y + distance * sin(rotation)); 
}
