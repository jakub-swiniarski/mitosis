#include <SFML/Graphics/Rect.hpp>
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
static sf::View camera;
static std::list<Food> food;
static Ball player(0.f, 0.f);
static sf::RenderWindow window(sf::VideoMode(cfg::window::WIDTH, cfg::window::HEIGHT), "Mitosis", sf::Style::None);

/* constants */
static const std::string FILEPATH = "res/";

/* function implementations */
void draw(void) {
    sf::FloatRect camera_rect(
        camera.getCenter().x - camera.getSize().x / 2.f,
        camera.getCenter().y - camera.getSize().y / 2.f,
        camera.getSize().x,
        camera.getSize().y
    );
    
    window.clear();
    
    for (auto const &i : food)
        if (camera_rect.intersects(i.getGlobalBounds()))
            window.draw(i);
    window.draw(player);
    
    window.display();
}

void run(void) {
    sf::Clock dt_clock;
    EventHandler event_handler(&window);
    InputProcessor input_processor(&player, &window);
    sf::Clock spawn_clock;

    while (window.isOpen()) {
        float dt = dt_clock.restart().asSeconds();

        event_handler.update();
        input_processor.update();

        player.update(dt);

        /* TODO: spawner class and simplify spawning algorithm */
        if (spawn_clock.getElapsedTime().asSeconds() >= cfg::food::SPAWN_COOLDOWN) {
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

        camera = window.getView();
        camera.setCenter(player.get_middle());
        window.setView(camera);

        draw();
    }
}

void setup(void) {
    window.setFramerateLimit(cfg::window::FPS);
}

int main(void) {
    setup();    
    run();

    return 0;
}
