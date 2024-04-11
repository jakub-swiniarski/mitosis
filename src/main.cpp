#include <SFML/Graphics/RenderWindow.hpp>

#include "Ball.hpp"
#include "EventHandler.hpp"

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static Ball player(100.f, 100.f);
static sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mitosis", sf::Style::None);
static Ball reference_ball(200.f, 200.f);

/* constants */
static const std::string FILEPATH = "res/";

/* function implementations */
void draw(void) {
    window.clear();
    
    window.draw(player);
    window.draw(reference_ball);
    
    window.display();
}

void run(void) {
    EventHandler event_handler(&window);
    sf::Clock dt_clock;

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        event_handler.update();
        player.update(dt);
        reference_ball.update(dt);

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
