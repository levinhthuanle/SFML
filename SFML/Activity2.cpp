#include "Activity2.h"

void Activity2::courseInformationStudent(Subject subject)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View Course", sf::Style::Close | sf::Style::Titlebar);
   
    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/YourCourseStudent.png"))
        std::cout << "Could not load the YourCourseStudent image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(textureNext);

    const sf::Color black = sf::Color(18, 2, 2);
    const int textSize = 36;
    Text courseId(110, 132, "Course Id: " + subject.courseId, fontNext, black, textSize);
    Text courseName(110, 182, "Course name: " + subject.courseName, fontNext, black, textSize);
    Text teacherName(110, 232, "Teacher name: " + subject.teacherName, fontNext, black, textSize);
    Text credits(110, 282, "Number of credits: " + std::to_string(subject.credits), fontNext, black, textSize);
    Text time(110, 332, "Time: " + subject.days + " - " + subject.time, fontNext, black, textSize);


    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        courseId.draw(windowNext);
        courseName.draw(windowNext);
        teacherName.draw(windowNext);
        credits.draw(windowNext);
        time.draw(windowNext);
        windowNext.display();
    }
}
