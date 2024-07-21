#include "Counter.hpp"

#include "config.hpp"

Counter::Counter(int value, std::string label, sf::Vector2f position, sf::Font& font)
    : value(value),
      label(label) {
    text.setPosition(position);
    text.setFont(font);
    text.setCharacterSize(cfg::text::size);
    text.setString(label + std::to_string(value));
}

sf::Text& Counter::get_text(void) {
    return text;
}

void Counter::update(int diff) {
    value += diff;
    text.setString(label + std::to_string(value));
}
