#include "Components.h"

InputField::InputField(float x, float y, float width, float height, sf::Font& font)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(0.f);
    //shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(int(height * 0.7));
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5.f, y + 5.f);

    cursor.setFont(font);
    cursor.setCharacterSize(int(height * 0.7));
    cursor.setFillColor(sf::Color::Black);

    nextField = false;
    showCursor = false;
    selected = false;
}

InputField::InputField(float x, float y, float width, float height, sf::Font& font, std::string defaultText)
{  //initiate inputfield which already had text, like in courses's scoreboard in staff view
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(0.f);
    //shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(int(height * 0.7));
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5.f, y + 5.f);

    cursor.setFont(font);
    cursor.setCharacterSize(int(height * 0.7));
    cursor.setFillColor(sf::Color::Black);

    //set default text
    input = defaultText;
    text.setString(input);

    nextField = false;
    showCursor = false;
    selected = false;
}

void InputField::setSelected(bool isSelected)
{
    selected = isSelected;
    //if (selected)
    //    shape.setOutlineColor(sf::Color::Blue);
    //else
    //    shape.setOutlineColor(sf::Color::Black);
}

bool InputField::isSelected(){
    return selected;
}

bool InputField::chooseNextField()
{
    if (nextField) {
        nextField = false;
        return true;
    }
    return false;
}

void InputField::processInput(sf::Event& event)
{
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

std::string InputField::getInput(){
    return input;
}

bool InputField::contains(const sf::Vector2i& mousePos){
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void InputField::handleMouseClick(const sf::Vector2i& mousePos){
    selected = contains(mousePos);
    setSelected(selected);
}

void InputField::draw(sf::RenderWindow& window){
    window.draw(shape);
    window.draw(text);
    window.draw(cursor);
}

void InputField::setText(std::string content){
    text.setString(content);
}

void InputField::textCursor(std::string input){
    text.setString(input);
    cursor.setPosition(getCursorPos());

    if (!showCursor) {
        if (clock.getElapsedTime().asSeconds() >= 0.7f) {
            cursor.setString("|");
            clock.restart();
            showCursor = true;
        }
    }
    else {
        if (clock.getElapsedTime().asSeconds() >= 0.7f) {
            cursor.setString("");
            clock.restart();
            showCursor = false;
        }
    }
}

Button::Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(fillColor);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(int(height / 2 + 5));
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10.f, y + 10.f);

}

void Button::draw(sf::RenderWindow& window){
    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(const sf::Vector2i& mousePos){
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

Circle::Circle(float x, float y, float radius, const std::string& pathToImg, const sf::Color& fillColor){
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

bool Circle::isClicked(const sf::Vector2i& mousePos){
    sf::Vector2f circleCenter = circle.getPosition();
    float circleRadius = circle.getRadius();

    // Calculate distance between mouse position and circle center
    double distance = std::sqrt(std::pow(mousePos.x - circleCenter.x, 2) + std::pow(mousePos.y - circleCenter.y, 2));

    // If distance is less than or equal to circle radius, the mouse is inside the circle
    return (distance <= circleRadius);
}

void Circle::draw(sf::RenderWindow& window){
    window.draw(circle);
    window.draw(sprite);
}

Text::Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size){
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setString(content);
    text.setPosition(x, y);
}

std::string Text::getContent(){
    return text.getString();
}

void Text::setString(const std::string& str){
    text.setString(str);
}

void Text::setPosition(float x, float y){
    text.setPosition(x, y);
}

void Text::setColor(const sf::Color& color){
    text.setFillColor(color);
}

void Text::setSize(unsigned int size){
    text.setCharacterSize(size);
}

void Text::draw(sf::RenderWindow& window){
    window.draw(text);
}

Calendar::Calendar(){
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

    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color(100, 100, 100));
    text.setString(s);
    text.setPosition(1384, 169);

}

void Calendar::draw(sf::RenderWindow& window){
    window.draw(text);
}

courseButton::courseButton(float x, float y, Subject& infor, sf::Font& font){
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

courseButton::courseButton(float x, float y, Course& infor, sf::Font& font)
{
    crs = infor;

    const float width = 250.f, height = 186.f, thickness = 6.f;
    const sf::Color fillColor = sf::Color(245, 244, 244), outlineColor = sf::Color(81, 161, 147);

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height)); 
    shape.setFillColor(fillColor); 
    shape.setOutlineThickness(thickness); 
    shape.setOutlineColor(outlineColor); 

    courseId.setFont(font); 
    courseId.setString(infor.getID()); 
    courseId.setCharacterSize(36);
    courseId.setFillColor(outlineColor);
    courseId.setPosition(x + 10.f, y + 10.f);
    courseId.setOutlineColor(outlineColor);
    courseId.setOutlineThickness(1.f);

    courseName.setFont(font);
    courseName.setString(infor.getName());
    courseName.setCharacterSize(16);
    courseName.setFillColor(outlineColor);
    courseName.setPosition(x + 10.f, y + 50.f);

    teacherName.setFont(font);
    teacherName.setString(infor.getTeacher());
    teacherName.setCharacterSize(16);
    teacherName.setFillColor(outlineColor);
    teacherName.setPosition(x + 10.f, y + 100.f);

    time.setFont(font);
    time.setString(infor.getDay());
    time.setCharacterSize(16);
    time.setFillColor(sf::Color(218, 110, 50));
    time.setPosition(x + 10.f, y + 120.f);

    credits.setFont(font);
    credits.setString("Number of credit: " + std::to_string(infor.getCredit()));
    credits.setCharacterSize(16);
    credits.setFillColor(sf::Color(218, 110, 50));
    credits.setPosition(x + 10.f, y + 140.f);

    seeMore.setFont(font);
    seeMore.setString("See more >> ");
    seeMore.setCharacterSize(16);
    seeMore.setFillColor(sf::Color(218, 110, 50));
    seeMore.setPosition(x + 10.f, y + 160.f);
}

void courseButton::update(Course& infor) {
    crs = infor;
    courseId.setString(infor.getID());
    courseName.setString(infor.getName());
    teacherName.setString(infor.getTeacher());
    time.setString(infor.getDay());
    credits.setString("Number of credit: " + std::to_string(infor.getCredit()));
}

void courseButton::draw(sf::RenderWindow& window){
    window.draw(shape);
    window.draw(courseId);
    window.draw(courseName);
    window.draw(teacherName);
    window.draw(time);
    window.draw(credits);
    window.draw(seeMore);
}

bool courseButton::isClicked(const sf::Vector2i& mousePos){
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

semesterButton::semesterButton(float x, float y, Semester& infor, sf::Font& font)
{
    semester = infor;
    const float width = 181.f, height = 55.f, thickness = 2.f;
    const sf::Color fillColor = sf::Color(218, 110, 50), outlineColor = sf::Color(255, 255, 255);

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(fillColor);


    text.setFont(font);
    text.setString(infor.getName());
    text.setCharacterSize(30);
    text.setFillColor(outlineColor);
    text.setPosition(x + 10.f, y + 10.f);

}

void semesterButton::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(text);
}

bool semesterButton::isClick(const sf::Vector2i& mousePos)
{
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
schoolyearButton::schoolyearButton(float x, float y, SchoolYear& infor, sf::Font& font)
{
    schoolYear = infor;

    const float width = 1220.f, height = 2.f, thickness = 2.f;
    const sf::Color black = sf::Color(30, 30, 30);

    std::string fiY = infor.getYear().substr(0, 2);
    std::string seY = infor.getYear().substr(3, 2);
    std::string YEAR = "20" + fiY + " - 20" + seY;

    shape.setPosition(sf::Vector2f(x, y + 50));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(black);

    text.setFont(font);
    text.setString(YEAR);
    text.setCharacterSize(36);
    text.setFillColor(black);
    text.setPosition(x, y);

    if (infor.semester.size() == 3) {
        s1 = s2 = s3 = true;
        sem1 = semesterButton(x + 15, y + 70, infor.semester[0], font);
        sem2 = semesterButton(x + 15 + 220, y + 70, infor.semester[1], font);
        sem3 = semesterButton(x + 15  + 220 + 220, y + 70, infor.semester[2], font);
    }
    else if (infor.semester.size() == 2) {
        s1 = s2 = true;
        sem1 = semesterButton(x + 15, y + 70, infor.semester[0], font);
        sem2 = semesterButton(x + 15 + 220, y + 70, infor.semester[1], font);

    }
    else if (infor.semester.size() == 1) {
        s1 = true;
        sem1 = semesterButton(x + 15, y + 70, infor.semester[0], font);
    }

}

void schoolyearButton::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(text);

    if (s1) sem1.draw(window);
    if (s2) sem2.draw(window);
    if (s3) sem3.draw(window);
}

allCourseMenu::allCourseMenu(float x, float y, SchoolYear& schoolyear, sf::Font& font)
{
    this->schoolyear = schoolyear;
    std::string fiY = schoolyear.getYear().substr(0, 2);
    std::string seY = schoolyear.getYear().substr(3, 2);
    std::string YEAR = "20" + fiY + " - 20" + seY;

    schoolyearTxt = Text(x, y, YEAR, font, BLACK, 32);
    line = Button(x, y + 50, 1130, 0, "", font, BLACK);
    
    s1 = Text(x + 10, y + 70, "Semester1: ",font, GREEN, 32);

    if (schoolyear.semester.size() > 0)
    for (int i = 0; i < schoolyear.semester[0].courses.size(); i++) {
        std::string temp = schoolyear.semester[0].courses[i].getID();
        Button tempBtn(x + 200 + 130 * (i % 10), y + 70, 100, 35, temp, font, ORANGE);
        listCoursesBtn1.push_back(tempBtn);
    }

    s2 = Text(x + 10, y + 122, "Semester2: ",font, GREEN, 32);
    if (schoolyear.semester.size() > 1)
    for (int i = 0; i < schoolyear.semester[1].courses.size(); i++) {
        std::string temp = schoolyear.semester[1].courses[i].getID();
        Button tempBtn(x + 200 + 130 * (i % 10), y + 122, 100, 35, temp, font, ORANGE);
        listCoursesBtn2.push_back(tempBtn);
    }

    s3 = Text(x + 10, y + 174, "Semester3: ",font, GREEN, 32);
    if (schoolyear.semester.size() > 2)
    for (int i = 0; i < schoolyear.semester[2].courses.size(); i++) {
        std::string temp = schoolyear.semester[2].courses[i].getID();
        Button tempBtn(x + 200 + 130 * (i % 10), y + 174, 100, 35, temp, font, ORANGE);
        listCoursesBtn3.push_back(tempBtn);
    }
}

void allCourseMenu::draw(sf::RenderWindow& window)
{
    schoolyearTxt.draw(window);
    line.draw(window);
    s1.draw(window);
    s2.draw(window);
    s3.draw(window);

    for (int i = 0; i < listCoursesBtn1.size(); i++)
        listCoursesBtn1[i].draw(window);

    for (int i = 0; i < listCoursesBtn2.size(); i++)
        listCoursesBtn2[i].draw(window);

    for (int i = 0; i < listCoursesBtn3.size(); i++)
        listCoursesBtn3[i].draw(window);
}
