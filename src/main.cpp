#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.hpp"

#include "config.hpp"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(cfg::window::width, cfg::window::height), "Mitosis", sf::Style::None);
    Game game(&window);
    game.run();
    
    return 0;
}
