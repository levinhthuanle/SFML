#include "Activity2.h"

void Activity2::popup(std::string content)
{
    //PopUp.png
    sf::RenderWindow windowNext(sf::VideoMode(636, 301), "Notification", sf::Style::Close | sf::Style::Titlebar);
    windowNext.setPosition(sf::Vector2i(500, 400));

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/PopUp.png"))
        std::cout << "Could not load the popup image" << std::endl;
    std::cout << "Generate popup sucess" << std::endl;
    sf::Sprite background(textureNext);
    Button okBtn(246.f, 241.f, 143, 45, "OKAY", fontNext, sf::Color(144, 44, 44));
    Text text(140, 95, content, fontNext, sf::Color(18, 2, 2), 20);

    
    while (windowNext.isOpen()) {
        sf::Event event;

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (okBtn.isClicked(mousePos))
                    windowNext.close();
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        text.draw(windowNext);
        okBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::courseInformationStudent(Subject& subject)
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
    Text enterSYtxt(120.f, 137.f, "Enter new schoolyear:", fontNext, sf::Color(26, 114, 98), 36);
    InputField enterSYinput(503, 131, 454, 66, fontNext);
    Button enterBtn(1011.f, 131.f, 245.f, 66.f, "Submit", fontNext, sf::Color(218, 110, 50));

    while (windowNext.isOpen()) {
        sf::Event event;
        if (enterSYinput.isSelected())
            enterSYinput.textCursor(enterSYinput.getInput());

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                enterSYinput.handleMouseClick(mousePos);
                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (enterBtn.isClicked(mousePos)) {
                    std::cout << enterSYinput.getInput() << std::endl;
                    popup("Create succesful");
                }
            }

            enterSYinput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        enterSYinput.draw(windowNext);
        enterSYtxt.draw(windowNext);
        enterBtn.draw(windowNext);
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::createSemesterStaff(SchoolYear& SY)
{
    //CreateSemesterStaff.png
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Create Semester", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/CreateSemesterStaff.png"))
        std::cout << "Could not load the CreateSemesterStaff image" << std::endl;
    std::cout << "Generate Create Semester Staff sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    Text enterStarttxt(120.f, 137.f, "Enter start date:", fontNext, sf::Color(26, 114, 98), 36);
    Text enterEndtxt(120.f, 220.f, "Enter end date:", fontNext, sf::Color(26, 114, 98), 36);
    InputField enterStartInput(503, 131, 454, 66, fontNext);
    InputField enterEndInput(503, 220, 454, 66, fontNext);
    Button enterBtn(1011.f, 151.f, 245.f, 66.f, "Submit", fontNext, sf::Color(218, 110, 50));

    while (windowNext.isOpen()) {
        sf::Event event;
        if (enterStartInput.isSelected()) enterStartInput.textCursor(enterStartInput.getInput());
        if (enterEndInput.isSelected()) enterEndInput.textCursor(enterEndInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                enterStartInput.handleMouseClick(mousePos);
                enterEndInput.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (enterBtn.isClicked(mousePos)) {
                    std::cout << enterStartInput.getInput() << std::endl;
                    std::cout << enterEndInput.getInput() << std::endl;
                    
                }
            }
            enterStartInput.processInput(event);
            if (enterStartInput.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                enterEndInput.setSelected(true);
            }
            enterEndInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        enterStartInput.draw(windowNext);
        enterEndInput.draw(windowNext);
        enterStarttxt.draw(windowNext);
        enterEndtxt.draw(windowNext);
        enterBtn.draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::viewAllCourseStaff(vector<Course>& course)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "All Course", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewAllCourseStaff.png"))
        std::cout << "Could not load the YourCourseStudent image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    vector<Text> allOfCourse;
    for (int i = 0; i < course.size(); i++) {
        Text temp(100.f, 100.f + 30 * i, course[i].getID(), fontNext, sf::Color(30, 30, 30), 25);
        allOfCourse.push_back(temp);
    }


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
        for (int i = 0; i < course.size(); i++) {
            allOfCourse[i].draw(windowNext);
        }
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
    return; 
}

void Activity2::viewCourseInSemester(Semester& semester)
{
    int displayFrom = 0;
    const sf::Color GREEN = sf::Color(26, 114, 98);
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View a semester", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture textureNext;
    sf::Font fontNext;
    
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    if (!textureNext.loadFromFile("Assets/ViewCourseStaff.png"))
        std::cout << "Could not load the ViewCourseStaff image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button nextPageBtn(1226.f, 750.f, 92.f, 62.f, "Next", fontNext, sf::Color(218, 110, 50));
    Button prevPageBtn(1226.f, 827.f, 92.f, 62.f, "Prev", fontNext, sf::Color(218, 110, 50));
    

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    Text text(65, 114, semester.getName() + ':', fontNext, green, 36);

    vector<courseButton> allOfCourse;
    //std::cout << semester.courses[0].getID() << std::endl;
    
    //courseButton temp(65, 209, semester.courses[0], fontNext);

    for (int i = 0; i < semester.courses.size(); i++) {
        courseButton temp(65 + 273*(i % 5), 209 + 210 * (i/5), semester.courses[i], fontNext);
        allOfCourse.push_back(temp);

        std::cout << semester.courses[i].getID() << std::endl;
        //std::cout << semester.courses[i].
    }

    while (windowNext.isOpen()) {
        long long limitDisplay = (displayFrom + 4) > allOfCourse.size() ? allOfCourse.size() : (displayFrom + 4);

        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - 4 >= 0)
                        displayFrom -= 4;
                }

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + 4 <= allOfCourse.size())
                        displayFrom += 4;
                }
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        text.draw(windowNext);
        for (int i = displayFrom; i < limitDisplay; i++) {
            allOfCourse[i].draw(windowNext);
        }

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::viewOneClass(Class& oneclass)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View a class", sf::Style::Close | sf::Style::Titlebar);
    std::cout << oneclass.classID << std::endl;

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewOneClassStaff.png"))
        std::cout << "Could not load the ViewOneClassStaff image" << std::endl;
    std::cout << "Generate View a class sucess" << std::endl;
    sf::Sprite background(textureNext);

    const sf::Color BLACK = sf::Color(18, 2, 2);
    const sf::Color GREEN = sf::Color(26, 114, 98);
    const sf::Color RED = sf::Color(144, 44, 44);
    const sf::Color ORANGE = sf::Color(218, 110, 50);
    Text no(82, 136, "No", fontNext, GREEN, 32);
    Text studentID(152, 136, "Student's ID", fontNext, GREEN, 32);
    Text studentName(536, 136, "Student's Name", fontNext, GREEN, 32);
    Text gender(1050, 136, "Gender", fontNext, GREEN, 32);
    Button line1(82, 174, 1133, 0, "", fontNext, BLACK);
    Button line2(135, 136, 0, 630, "", fontNext, BLACK);
    Button line3(513, 136, 0, 630, "", fontNext, BLACK);
    Button line4(1044, 136, 0, 630, "", fontNext, BLACK);

    Button addStudentBtn(1470.f, 117.f, 163.f, 57.f, "Add", fontNext, RED);
    Button removeStudentBtn(1470.f, 191.f, 163.f, 57.f, "Remove", fontNext, RED);

    vector<Text> listOfStudent;
    for (int i = 0; i < oneclass.students.size(); i++) {
        std::string temp = std::to_string(i + 1) + "    ";
        if (temp.size() == 5)
            temp = '0' + temp;

        temp = temp + oneclass.students[i].getID() + "                           ";
        temp += oneclass.students[i].getFullname();
        for (int j = 1; j <= 47 - oneclass.students[i].getFullname().size(); j++)
            temp += ' ';
        temp += oneclass.students[i].getGender();
        
        Text text(82.f, 188.f + 32*i, temp, fontNext, BLACK, 32);

        listOfStudent.push_back(text);
    }


    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    vector<Text> allOfStudents;



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

        no.draw(windowNext);
        studentID.draw(windowNext);
        studentName.draw(windowNext);
        gender.draw(windowNext);
        line1.draw(windowNext);
        line2.draw(windowNext);
        line3.draw(windowNext);
        line4.draw(windowNext);

        addStudentBtn.draw(windowNext);
        removeStudentBtn.draw(windowNext);

        for (int i = 0; i < listOfStudent.size(); i++)
            listOfStudent[i].draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::viewAllClassStaff(vector<Class>& allClass)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View all class", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewAllClassStaff.png"))
        std::cout << "Could not load the ViewAllClassStaff image" << std::endl;
    std::cout << "Generate View all class sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    vector<Button> allOfClasses;
    for (int i = 0; i < allClass.size(); i++) {
        Button temp(100.f + 315*(i % 5), 135.f + 90*(i / 5), 245.f, 66.f, allClass[i].classID, fontNext, sf::Color(26, 114, 96));
        allOfClasses.push_back(temp);
    }


    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                for (int i = 0; i < allOfClasses.size(); i++) {
                    if (allOfClasses[i].isClicked(mousePos))
                        viewOneClass(allClass[i]);
                }
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        for (int i = 0; i < allOfClasses.size(); i++) {
            allOfClasses[i].draw(windowNext);
        }

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::addClassStaff()
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Add a class", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/AddClassStaff.png"))
        std::cout << "Could not load the AddClassStaff image" << std::endl;
    std::cout << "Generate The Add Class sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, orange);
    Text enterClasstxt(120.f, 137.f, "Enter new Class:", fontNext, sf::Color(26, 114, 98), 36);
    InputField enterClassInput(503, 131, 454, 66, fontNext);
    Button enterBtn(1011.f, 131.f, 245.f, 66.f, "Submit", fontNext, sf::Color(218, 110, 50));


    while (windowNext.isOpen()) {
        sf::Event event;
        if (enterClassInput.isSelected())
            enterClassInput.textCursor(enterClassInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                enterClassInput.handleMouseClick(mousePos);
                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();
            }
            enterClassInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        enterClassInput.draw(windowNext);
        enterBtn.draw(windowNext);
        enterClasstxt.draw(windowNext);
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}
