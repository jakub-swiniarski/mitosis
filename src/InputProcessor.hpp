#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class Cell;
namespace sf {
    class WindowBase;
}

class InputProcessor {
    Cell*           player;
    sf::WindowBase& window;

public:
    InputProcessor(Cell* player, sf::WindowBase& window);

    void update(void) const;
};

#endif // INPUTPROCESSOR_HPP
