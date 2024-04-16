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

    const int textSize = 36;
    Text courseId(110, 132, "Course Id: " + subject.courseId, fontNext, black, textSize);
    Text courseName(110, 182, "Course name: " + subject.courseName, fontNext, black, textSize);
    Text teacherName(110, 232, "Teacher name: " + subject.teacherName, fontNext, black, textSize);
    Text credits(110, 282, "Number of credits: " + std::to_string(subject.credits), fontNext, black, textSize);
    Text time(110, 332, "Time: " + subject.days + " - " + subject.time, fontNext, black, textSize);
    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    
    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        if (subject.completed == false) {
            Text uncompleted(110, 382, "This course is not be scored!", fontNext, black, textSize);
            uncompleted.draw(windowNext);
        }
        else {
            Text typeOfScorse(110, 425, "Midterm\t Practice\t Plus\t Other\t Final\t Overall", fontNext, green, textSize);
            std::string Score = '\t' + std::to_string(subject.midScore) + "\t\t          " + std::to_string(subject.practiceScore) + "\t\t    ";
            Score += std::to_string(subject.plusScore) + "\t\t    " + std::to_string(subject.otherScore) + "\t\t  ";
            Score += std::to_string(subject.finalScore) + "\t\t      " + std::to_string(subject.aveScore);
            Text score(110, 460, Score, fontNext, orange, textSize);

            typeOfScorse.draw(windowNext);
            score.draw(windowNext);
        }

        courseId.draw(windowNext);
        courseName.draw(windowNext);
        teacherName.draw(windowNext);
        credits.draw(windowNext);
        time.draw(windowNext);
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

// createSYStaff.png
void Activity2::createNewSchoolYearStaff()
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Create School Year", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/createSYStaff.png"))
        std::cout << "Could not load the YourCourseStudent image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    

    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}
