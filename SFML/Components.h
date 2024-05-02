#pragma once
#include "ExtraFunction.h"
#include "Subject.h"
#include "SchoolYear.h"
#include <iomanip>

class InputField {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Text cursor;
    bool selected;
    
    sf::Clock clock;
    bool showCursor;    //When selected, if the text cursor "|" is shown
    bool nextField;     //Automatically choose the next field

public:
    std::string input;
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

    sf::Vector2f getCursorPos() {
        return text.findCharacterPos(input.length());
    }
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

    Button& operator=(const Button& rhs) {
        if (this == &rhs) return *this;
        this->shape = rhs.shape;
        this->text = rhs.text;

        return *this;
    }
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

    Text& operator=(const Text& rhs) {
        if (this == &rhs) return *this;
        this->text = rhs.text;
        this->font = rhs.font;
        return *this;
    }
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
    Course crs;
    courseButton() {}

    courseButton(float x, float y, Subject& infor, sf::Font& font);

    courseButton(float x, float y, Course& infor, sf::Font& font);

    void update(Course& infor);

    void draw(sf::RenderWindow& window);

    bool isClicked(const sf::Vector2i& mousePos);
};

class semesterButton {
public:
    sf::Text text;
    sf::RectangleShape shape;
    Semester semester;

    semesterButton() {}

    semesterButton(float x, float y, Semester& infor, sf::Font& font);

    void draw(sf::RenderWindow& window);

    bool isClick(const sf::Vector2i& mousePos);
};

class schoolyearButton {
public:

    sf::Text text;
    sf::RectangleShape shape;
    semesterButton sem1, sem2, sem3;
    bool s1 = false, s2 = false, s3 = false;
    SchoolYear schoolYear;

    schoolyearButton() {}

    schoolyearButton(float x, float y, SchoolYear& infor, sf::Font& font);

    void draw(sf::RenderWindow& window);
};

class allCourseMenu {
public:
    Text schoolyearTxt;
    Button line;
    Text s1, s2, s3;
    SchoolYear schoolyear;
    vector<Button> listCoursesBtn1, listCoursesBtn2, listCoursesBtn3;
    allCourseMenu() {}

    allCourseMenu(float x, float y, SchoolYear& schoolyear, sf::Font& font);

    void draw(sf::RenderWindow& window);
};