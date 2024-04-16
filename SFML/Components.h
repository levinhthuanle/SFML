#pragma once
#include "Subject.h"
#include <iomanip>

class InputField {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool selected;
    std::string input;
    sf::Clock clock;
    bool showCursor;    //When selected, if the text cursor "|" is shown
    bool nextField;     //Automatically choose the next field

public:
    InputField(float x, float y, float width, float height, sf::Font& font);

    InputField(float x, float y, float width, float height, sf::Font& font, std::string defaultText);

    void setSelected(bool isSelected);

    bool isSelected();

    bool chooseNextField();

    void processInput(sf::Event& event);

    std::string getInput();

    bool contains(const sf::Vector2i& mousePos);

    void handleMouseClick(const sf::Vector2i& mousePos);

    void draw(sf::RenderWindow& window);

    void setText(std::string content);

    void textCursor(std::string input);
};

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(){}

    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor);

    void draw(sf::RenderWindow& window);

    bool isClicked(const sf::Vector2i& mousePos);
};

class Circle {
private:
    sf::CircleShape circle;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Circle(float x, float y, float radius, const std::string& pathToImg, const sf::Color& fillColor);

    bool isClicked(const sf::Vector2i& mousePos);

    void draw(sf::RenderWindow& window);
};

class Text {
private:
    sf::Text text;
    sf::Font font;

public:
    Text() {}

    Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size);

    std::string getContent();

    void setString(const std::string& str);

    void setPosition(float x, float y);

    void setColor(const sf::Color& color);

    void setSize(unsigned int size);

    void draw(sf::RenderWindow& window);
};

class Calendar {
public:
    sf::Font font;
    sf::Text text;

    Calendar();

    void draw(sf::RenderWindow& window);
};

class courseButton {
private:
    sf::RectangleShape shape;
    sf::Text courseId, courseName, teacherName, time, credits, seeMore;
    
public:
    Subject cnt;
    courseButton() {}

    courseButton(float x, float y, const Subject infor, sf::Font& font);

    void draw(sf::RenderWindow& window);

    bool isClicked(const sf::Vector2i& mousePos);
};