#ifndef GAME_HPP
#define GAME_HPP

#include <forward_list>
#include <SFML/Graphics/View.hpp>

#include "AICell.hpp"
#include "Food.hpp"

class Food;
namespace sf {
    class RenderWindow;
}

class Game {
    sf::View camera;
    AICell enemy;
    std::forward_list<Food> food;
    Cell player;
    sf::RenderWindow *window;

    void draw(void);

public:
    Game(sf::RenderWindow *w);
    void run(void);
};

#endif
