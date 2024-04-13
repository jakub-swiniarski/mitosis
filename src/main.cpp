#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include "Ball.hpp"
#include "EventHandler.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static Ball player(100.f, 100.f);
static Ball reference_ball(200.f, 200.f);
static sf::RenderWindow window(sf::VideoMode(cfg::Window::WIDTH, cfg::Window::HEIGHT), "Mitosis", sf::Style::None);

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
    sf::View camera;
    sf::Clock dt_clock;
    EventHandler event_handler(&window);
    InputProcessor input_processor(&player, &window);

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        event_handler.update();
        input_processor.update();

        player.update(dt);
        reference_ball.update(dt);

        camera = window.getView();
        camera.setCenter(player.get_middle());
        window.setView(camera);

        draw();
    }
}

void setup(void) {
    window.setFramerateLimit(cfg::Window::FPS);
}

int main(void) {
    setup();    
    run();

    return 0;
}
