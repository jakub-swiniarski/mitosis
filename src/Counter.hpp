#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

class Counter {
    int value;
    std::string label;
    sf::Text text;

public:
    Counter(int v, std::string l, sf::Vector2f pos, sf::Font &f);
    sf::Text &get_text(void);
    void update(int diff);
};

#endif /* COUNTER_HPP */
