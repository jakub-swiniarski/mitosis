#ifndef GAME_HPP
#define GAME_HPP

#include <forward_list>
#include <SFML/Graphics/View.hpp>

#include "Cell.hpp"
#include "Food.hpp"

namespace sf {
    class RenderWindow;
}

class Game {
    sf::View camera;
    std::forward_list<Cell> cells;
    std::forward_list<Food> food;
    sf::RenderWindow *window;

    void draw(void);

public:
    Game(sf::RenderWindow *w);
    void run(void);
};

#endif
