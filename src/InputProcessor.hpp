#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class Ball;
namespace sf {
    class Window;
}

class InputProcessor {
    Ball *player;
    sf::Window *window;

public:
    InputProcessor(Ball *p, sf::Window *w);
    void update(float mod);
};

#endif /* INPUTPROCESSOR_HPP */
