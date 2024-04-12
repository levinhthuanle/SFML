#pragma once
#include "Requirement.h"
#include "Subject.h"
#include <string>
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
    InputField(float x, float y, float width, float height, sf::Font& font) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(0.f);
        //shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(int(height * 0.7));
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 5.f, y + 5.f);

        nextField = false;
        showCursor = false;
        selected = false;
    }

    InputField(float x, float y, float width, float height, sf::Font& font, std::string defaultText) {  //initiate inputfield which already had text, like in courses's scoreboard in staff view
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(0.f);
        //shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(int(height * 0.7));
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 5.f, y + 5.f);

        //set default text
        input = defaultText;
        text.setString(input);

        nextField = false;
        showCursor = false;
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

    bool chooseNextField() {
        if (nextField) {
            nextField = false;
            return true;
        }
        return false;
    }

    void processInput(sf::Event& event) {
        if (selected) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!input.empty())
                        input.pop_back();
                }
                else if (event.text.unicode == '\r') {  // Set unselected for ENTER input
                    selected = false;
                    nextField = true;
                }
                else if (event.text.unicode == '\t') {  // Set unselected for TAB input
                    selected = false;
                    nextField = true;
                }
                else if (event.text.unicode < 128) {
                    input += static_cast<char>(event.text.unicode);
                }
            }
        }
        else text.setString(input);
        setSelected(selected); 
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

    void setText(std::string content) {
        text.setString(content);
    }

    void textCursor(std::string input) {
        if (!showCursor) {
            if (clock.getElapsedTime().asSeconds() >= 0.4f) {
                text.setString(input + "|");
                clock.restart();
                showCursor = true;
            }
        }
        else {
            if (clock.getElapsedTime().asSeconds() >= 0.4f) {
                text.setString(input);
                clock.restart();
                showCursor = false;
            }
        }
    }
};

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(){}

    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(fillColor);
        shape.setOutlineThickness(2.f);
        shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(int(height/2 + 5));
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);

    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
};

class Circle {
private:
    sf::CircleShape circle;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Circle(float x, float y, float radius, const std::string& pathToImg, const sf::Color& fillColor) {
        // Initialize circle
        circle.setPosition(x, y);
        circle.setRadius(radius);
        circle.setFillColor(fillColor);
        circle.setOrigin(radius, radius); // Set origin to center
        circle.setOutlineThickness(1.f);
        circle.setOutlineColor(sf::Color::Black);

        // Load texture
        if (!texture.loadFromFile(pathToImg)) {
            std::cout << "Failed to load image";
            throw std::runtime_error("Failed to load image");
        }

        // Initialize sprite with texture
        sprite.setTexture(texture);
        sf::Vector2u textureSize = texture.getSize();
        sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // Set origin to center


        sprite.setPosition(x, y);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        sf::Vector2f circleCenter = circle.getPosition();
        float circleRadius = circle.getRadius();

        // Calculate distance between mouse position and circle center
        double distance = std::sqrt(std::pow(mousePos.x - circleCenter.x, 2) + std::pow(mousePos.y - circleCenter.y, 2));

        // If distance is less than or equal to circle radius, the mouse is inside the circle
        return (distance <= circleRadius);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(circle);
        window.draw(sprite);
    }
};

class Text {
private:
    sf::Text text;
    sf::Font font;

public:
    Text() {}

    Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(color);
        text.setString(content);
        text.setPosition(x, y);
    }

    std::string getContent() {
        return text.getString();
    }

    void setAttribute(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {
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

class Calendar {
public:
    sf::Font font;
    sf::Text text;
    Calendar(sf::Font font) {
        this->font = font;
        system("python calendar.py");
        std::ifstream fin;
        fin.open("data/calendar.txt");
        std::string s = "", temp;
        getline(fin, temp);
        s = s + '\n' + temp;
        fin.close();

        // Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {

        Text calendar(1402, 207, s, font, sf::Color(0, 0, 0), 25);
        Text days(1384, 133, "Mo Tu We Th Fr Sa Su", font, sf::Color(26, 114, 98), 25);

    }

    Calendar() {
        system("python calendar.py");
        std::ifstream fin;
        fin.open("data/calendar.txt");
        if (!fin.is_open())
            std::cout << "Could not open the calendar file" << std::endl;

        std::string s = "", temp;
        while (!fin.eof()) {
            getline(fin, temp);
            s = s + '\n' + temp;
        }
        
        fin.close();

        // Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {

        text.setFont(font);
        text.setCharacterSize(25);
        text.setFillColor(sf::Color(100, 100,100));
        text.setString(s);
        text.setPosition(1384, 169);

        //std::cout << text.getString().toAnsiString() << std::endl;
    }

    void draw(sf::RenderWindow& window){
        window.draw(text);
    }
};

class courseButton {
private:
    sf::RectangleShape shape;
    sf::Text courseId, courseName, teacherName, time, credits, seeMore;
    

public:
    Subject cnt;
    courseButton() {}

    courseButton(float x, float y, const Subject infor, sf::Font& font) {
        cnt = infor;
        const float width = 250.f, height = 186.f, thickness = 6.f;
        const sf::Color fillColor = sf::Color(245, 244, 244), outlineColor = sf::Color(81, 161, 147);
        
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(fillColor);
        shape.setOutlineThickness(thickness);
        shape.setOutlineColor(outlineColor);

        courseId.setFont(font);
        courseId.setString(infor.courseId);
        courseId.setCharacterSize(36);
        courseId.setFillColor(outlineColor);
        courseId.setPosition(x + 10.f, y + 10.f);
        courseId.setOutlineColor(outlineColor);
        courseId.setOutlineThickness(1.f);

        courseName.setFont(font);
        courseName.setString(infor.courseName);
        courseName.setCharacterSize(16);
        courseName.setFillColor(outlineColor);
        courseName.setPosition(x + 10.f, y + 50.f);
       
        teacherName.setFont(font);
        teacherName.setString(infor.teacherName);
        teacherName.setCharacterSize(16);
        teacherName.setFillColor(outlineColor);
        teacherName.setPosition(x + 10.f, y + 100.f);

        time.setFont(font);
        time.setString(infor.days + " " + infor.time);
        time.setCharacterSize(16);
        time.setFillColor(sf::Color(218, 110, 50));
        time.setPosition(x + 10.f, y + 120.f);

        credits.setFont(font);
        credits.setString("Number of credit: " + std::to_string(infor.credits));
        credits.setCharacterSize(16);
        credits.setFillColor(sf::Color(218, 110, 50));
        credits.setPosition(x + 10.f, y + 140.f);

        seeMore.setFont(font);
        seeMore.setString("See more >> ");
        seeMore.setCharacterSize(16);
        seeMore.setFillColor(sf::Color(218, 110, 50));
        seeMore.setPosition(x + 10.f, y + 160.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(courseId);
        window.draw(courseName);
        window.draw(teacherName);
        window.draw(time);
        window.draw(credits);
        window.draw(seeMore);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
};