#ifndef GAME_HPP
#define GAME_HPP

#include <list>
#include <SFML/Graphics/View.hpp>

#include "Cell.hpp"
#include "Counter.hpp"
#include "Food.hpp"

namespace sf {
    class RenderWindow;
}

class Game {
    // ----- CORE ----- //
    sf::RenderWindow& window;
    sf::View          camera;

    // ----- DRAWABLES ----- //
    std::list<Cell> cells;
    std::list<Food> food;
    Counter         counter;
    Cell*           player;

    // ----- RESOURCES ----- //
    std::string res_path;
    sf::Font    font;

public:
    Game(sf::RenderWindow& window);

    void run(void);
};

#endif // GAME_HPP
