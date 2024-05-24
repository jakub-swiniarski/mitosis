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
    sf::RenderWindow *window;
    sf::View camera;
    std::list<Cell> cells;
    std::list<Food> food;
    Cell *player;
    std::string filepath;
    sf::Font font;
    Counter counter;

public:
    Game(sf::RenderWindow *w);
    void run(void);
};

#endif /* GAME_HPP */
