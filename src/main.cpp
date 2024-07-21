#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

#include "Game.hpp"

#include "config.hpp"

int main(void) {
    try {
        sf::RenderWindow window(sf::VideoMode(cfg::window::width, cfg::window::height), "Mitosis", sf::Style::None);
        Game game(window);
        game.run();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        throw std::runtime_error("Unknown error");
    }

    return EXIT_SUCCESS;
}
