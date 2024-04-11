#include <SFML/Graphics/RenderWindow.hpp>

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mitosis", sf::Style::None);

/* constants */
static const std::string FILEPATH = "res/";

/* function implementations */
void draw(void) {
    window.clear();
    
    /* draw */
    
    window.display();
}

void run(void) {
    sf::Clock dt_clock;

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        draw();
    }
}

void setup(void) {
    window.setFramerateLimit(FPS);
}

int main(void) {
    setup();    
    run();

    return 0;
}
