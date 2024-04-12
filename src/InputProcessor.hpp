#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class Ball;

class InputProcessor {
    Ball *player;

public:
    InputProcessor(Ball *p);
    void update(float mod);
};

#endif /* INPUTPROCESSOR_HPP */
