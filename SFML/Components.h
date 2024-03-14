#pragma once
#include "Requirement.h"


class InputField {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool selected;
    std::string input;

public:
    InputField(float x, float y, float width, float height, sf::Font& font) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(0.f);
        //shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 5.f, y + 5.f);

        selected = false;
    }

    void setSelected(bool isSelected) {
        selected = isSelected;
        //if (selected)
        //    shape.setOutlineColor(sf::Color::Blue);
        //else
        //    shape.setOutlineColor(sf::Color::Black);
    }

    bool isSelected() const {
        return selected;
    }

    void processInput(sf::Event& event) {
        if (selected) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!input.empty())
                        input.pop_back();
                }
                else if (event.text.unicode < 128) {
                    input += static_cast<char>(event.text.unicode);
                }
                text.setString(input);
            }
        }
    }

    std::string getInput() const {
        return input;
    }

    bool contains(const sf::Vector2i& mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    void handleMouseClick(const sf::Vector2i& mousePos) {
        selected = contains(mousePos);
        setSelected(selected);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(fillColor);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(height/2 + 5);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);

        // Calculate position to center the text within the button
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
        text.setPosition(sf::Vector2f(x + width / 2.f, y + height / 2.f));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
};

class Text {
private:
    sf::Text text;
    sf::Font font;

public:
    Text(){}

    Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(color);
        text.setString(content);
        text.setPosition(x, y);
    }

    // Set text string
    void setString(const std::string& str) {
        text.setString(str);
    }

    // Set text position
    void setPosition(float x, float y) {
        text.setPosition(x, y);
    }

    // Set text color
    void setColor(const sf::Color& color) {
        text.setFillColor(color);
    }

    // Set text size
    void setSize(unsigned int size) {
        text.setCharacterSize(size);
    }

    // Draw text on SFML window
    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};