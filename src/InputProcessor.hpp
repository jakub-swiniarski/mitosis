#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class Ball;
namespace sf {
    class WindowBase;
}

class InputProcessor {
    Ball *player;
    sf::WindowBase *window;

public:
    InputProcessor(Ball *p, sf::WindowBase *w);
    void update(void) const;
};

#endif /* INPUTPROCESSOR_HPP */
