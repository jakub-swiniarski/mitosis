#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <list>

#include "Ball.hpp"
#include "EventHandler.hpp"
#include "Food.hpp"
#include "InputProcessor.hpp"

#include "config.hpp"

/* function declarations */
static void draw(void);
static void run(void);
static void setup(void);

/* variables */
static std::list<Food> food;
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

    for (auto const& i : food)
        window.draw(i);
    
    window.display();
}

void run(void) {
    sf::View camera;
    sf::Clock dt_clock;
    EventHandler event_handler(&window);
    InputProcessor input_processor(&player, &window);
    sf::Clock spawn_clock;

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        event_handler.update();
        input_processor.update();

        player.update(dt);
        reference_ball.update(dt);

        camera = window.getView();
        camera.setCenter(player.get_middle());
        window.setView(camera);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_clock.getElapsedTime().asSeconds() >= cfg::Food::SPAWN_COOLDOWN) {
            spawn_clock.restart();
            food.push_back(Food(player.getPosition().x, player.getPosition().y));
        }

        for (std::list<Food>::iterator i = food.begin(); i != food.end(); i++) {
            if (i->getGlobalBounds().intersects(player.getGlobalBounds())) {
                player.setRadius(player.getRadius() + i->getRadius() / 10.f);
                player.move(-i->getRadius() / 10.f, -i->getRadius() / 10.f);
                food.erase(i);
                break;
            }
        }

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
