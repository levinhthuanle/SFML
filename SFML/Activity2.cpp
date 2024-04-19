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
    Text courseId(110, 132, "Course Id: " + subject.courseId, fontNext, BLACK, textSize);
    Text courseName(110, 182, "Course name: " + subject.courseName, fontNext, BLACK, textSize);
    Text teacherName(110, 232, "Teacher name: " + subject.teacherName, fontNext, BLACK, textSize);
    Text credits(110, 282, "Number of credits: " + std::to_string(subject.credits), fontNext, BLACK, textSize);
    Text time(110, 332, "Time: " + subject.days + " - " + subject.time, fontNext, BLACK, textSize);
    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    
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
            Text uncompleted(110, 382, "This course is not be scored!", fontNext, BLACK, textSize);
            uncompleted.draw(windowNext);
        }
        else {
            Text typeOfScorse(110, 425, "Midterm\t Practice\t Plus\t Other\t Final\t Overall", fontNext, GREEN, textSize);
            std::string Score = '\t' + std::to_string(subject.midScore) + "\t\t          " + std::to_string(subject.practiceScore) + "\t\t    ";
            Score += std::to_string(subject.plusScore) + "\t\t    " + std::to_string(subject.otherScore) + "\t\t  ";
            Score += std::to_string(subject.finalScore) + "\t\t      " + std::to_string(subject.aveScore);
            Text score(110, 460, Score, fontNext, ORANGE, textSize);

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

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
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

void Activity2::createSemesterStaff(Semester& semester)
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

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Text enterStarttxt(120.f, 137.f, "Enter start date:", fontNext, sf::Color(26, 114, 98), 36);
    Text enterEndtxt(120.f, 220.f, "Enter end date:", fontNext, sf::Color(26, 114, 98), 36);

    //need to upgrade this later, by dividint the input field into 3 different part.
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
                    Date start(enterStartInput.getInput()); 
                    Date end(enterEndInput.getInput()); 
                    if (start.is_valid() && end.is_valid() && start < end)
                    {
                        semester.startDate = start;
                        semester.endDate = end; 
                        windowNext.close(); 
                    }
                    else
                    {
                        if (!start.is_valid())
                            popup("Invalid start day");
                        else if (!end.is_valid())
                            popup("Invalid end day");
                        else popup("The start day is bigger than the end day"); 

                        break; 
                    }
      
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

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
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
    

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Button addCourseBtn(1200, 114, 245, 66, "Add course", fontNext, ORANGE);
    Text text(65, 114, semester.getName() + ':', fontNext, GREEN, 36);

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

                for (int i = displayFrom; i < limitDisplay; i++) {
                    if (allOfCourse[i].isClicked(mousePos))
                        courseInformation(allOfCourse[i].crs);
                }

                if (addCourseBtn.isClicked(mousePos))
                    addCourse(semester);
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        text.draw(windowNext);
        for (int i = displayFrom; i < limitDisplay; i++) {
            allOfCourse[i].draw(windowNext);
        }

        addCourseBtn.draw(windowNext);
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::addCourse(Semester& semester)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Add course to Semester", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/AddClassStaff.png"))
        std::cout << "Could not load the Add course image" << std::endl;
    std::cout << "Generate The Add Course sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);

    Text courseIdTxt(72, 218, "Course ID: ", fontNext, BLACK, 26);
    Text courseNameTxt(72, 275, "Course name: ", fontNext, BLACK, 26);
    Text teacherNameTxt(72, 348, "Teacher Name: ", fontNext, BLACK, 26);
    Text sessionTxt(72, 421, "Session:", fontNext, BLACK, 26);
    Text numberCreditTxt(858, 218, "Maximum students", fontNext, BLACK, 26);
    Text maxStudentTxt(858, 290, "Date Of Birth:", fontNext, BLACK, 26);
    Text dayTxt(858, 364, "Days in a week", fontNext, BLACK, 26);
    

    InputField courseIdInput(411, 202, 385, 47, fontNext);
    InputField courseNameInput(411, 275, 385, 47, fontNext);
    InputField teacherNameInput(411, 348, 385, 47, fontNext);
    InputField sessionInput(411, 421, 385, 47, fontNext);
    InputField numberCreditInput(1189, 202, 385, 47, fontNext);
    InputField maxStudentInput(1189, 275, 385, 47, fontNext);
    InputField dayInput(1189, 348, 385, 47, fontNext);

    Button submitBtn(859, 416, 245, 50, "Submit", fontNext, ORANGE);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (courseIdInput.isSelected()) courseIdInput.textCursor(courseIdInput.getInput());
        if (courseNameInput.isSelected()) courseNameInput.textCursor(courseNameInput.getInput());
        if (teacherNameInput.isSelected()) teacherNameInput.textCursor(teacherNameInput.getInput());
        if (sessionInput.isSelected()) sessionInput.textCursor(sessionInput.getInput());
        if (numberCreditInput.isSelected()) numberCreditInput.textCursor(numberCreditInput.getInput());
        if (maxStudentInput.isSelected()) maxStudentInput.textCursor(maxStudentInput.getInput());
        if (dayInput.isSelected()) dayInput.textCursor(dayInput.getInput());


        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                courseIdInput.handleMouseClick(mousePos);
                courseNameInput.handleMouseClick(mousePos);
                teacherNameInput.handleMouseClick(mousePos);
                sessionInput.handleMouseClick(mousePos);
                numberCreditInput.handleMouseClick(mousePos);
                maxStudentInput.handleMouseClick(mousePos);
                dayInput.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (submitBtn.isClicked(mousePos)) {
                    // Create a new course here
                    // I dont know how to push the information in a correct way. You can use .getInput() function to get the data
                }
            }
            courseIdInput.processInput(event);
            courseNameInput.processInput(event);
            teacherNameInput.processInput(event);
            sessionInput.processInput(event);
            numberCreditInput.processInput(event);
            maxStudentInput.processInput(event);
            dayInput.processInput(event);


        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);


        courseIdTxt.draw(windowNext);
        courseNameTxt.draw(windowNext);
        teacherNameTxt.draw(windowNext);
        sessionTxt.draw(windowNext);
        numberCreditTxt.draw(windowNext);
        maxStudentTxt.draw(windowNext);
        dayTxt.draw(windowNext);

        courseIdInput.draw(windowNext);
        courseNameInput.draw(windowNext);
        teacherNameInput.draw(windowNext);
        sessionInput.draw(windowNext);
        numberCreditInput.draw(windowNext);
        maxStudentInput.draw(windowNext);
        dayInput.draw(windowNext);


        submitBtn.draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::courseInformation(Course& course)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Course information", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/AddClassStaff.png"))
        std::cout << "Could not load the Course information image" << std::endl;
    std::cout << "Generate The course information sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);

    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
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


    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
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

                if (removeStudentBtn.isClicked(mousePos))
                    removeStudent(oneclass);

                if (addStudentBtn.isClicked(mousePos))
                    addStudent(oneclass);
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

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
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

void Activity2::addClassStaff(std::string lastYear, Class &tempClass)
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

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Text enterClasstxt(120.f, 137.f, "Enter new Class:", fontNext, sf::Color(26, 114, 98), 36);
    Text lastYeartxt(450, 135,lastYear, fontNext, sf::Color(11, 10, 10), 45);
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
                else if (enterBtn.isClicked(mousePos))
                {
                   
                    std::string ClassCourse = enterClassInput.getInput(); 
                    if (ClassCourse.size() != 4)
                    {
                        std::cerr << "Wrong format of a Class. Try again";
                        popup("Wrong format of a Class. Try again!");
                        enterClassInput.input = "";
                        break; 
                    }
                   
                    else
                    {
                        Class actualClass(lastYear + ClassCourse); 
                        
                        if (actualClass.is_existed())
                        {
                            std::cerr << "This class is existed. Try again. "; 
                            enterClassInput.input = "";
                            popup("This class is existed. Try again!");
                            break; 
                        }
                        tempClass = actualClass; 
                        
                        windowNext.close(); 
                    }
                }
                
            }
            enterClassInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        enterClassInput.draw(windowNext);
        enterBtn.draw(windowNext);
        enterClasstxt.draw(windowNext);
        lastYeartxt.draw(windowNext); 
        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::removeStudent(Class& oneclasss)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Remove a student", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/AddClassStaff.png"))
        std::cout << "Could not load the Remove Student image" << std::endl;
    std::cout << "Generate The Add Class sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Text enterSYtxt(120.f, 137.f, "Enter Student's ID:", fontNext, sf::Color(26, 114, 98), 36);
    InputField enterSYinput(503, 131, 454, 66, fontNext);
    Button enterBtn(1011.f, 131.f, 245.f, 66.f, "Submit", fontNext, sf::Color(218, 110, 50));

    while (windowNext.isOpen()) {
        sf::Event event;
        if (enterSYinput.isSelected())
            enterSYinput.textCursor(enterSYinput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                enterSYinput.handleMouseClick(mousePos);
                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();
                
                if (enterBtn.isClicked(mousePos)) {
                    std::cout << enterSYinput.getInput() << std::endl;
                    // This is the id of the student that need to delete
                    
                    popup("Remove succesful");
                    return;
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

void Activity2::addStudent(Class& oneclass)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Add a student", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/AddClassStaff.png"))
        std::cout << "Could not load the Remove Student image" << std::endl;
    std::cout << "Generate The Add Class sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Text enterSYtxt(120.f, 137.f, "Enter Student's ID:", fontNext, sf::Color(26, 114, 98), 36);
    InputField enterSYinput(503, 131, 454, 66, fontNext);
    Button enterBtn(1011.f, 131.f, 245.f, 66.f, "Submit", fontNext, sf::Color(218, 110, 50));

    Text csvTxt(72, 128, "Enter the path of csv file:", fontNext, BLACK, 26);
    Text orTxt(72, 195, "OR", fontNext, BLACK, 26);
    //  No, Student ID, First name, Last name, Gender, Date of Birth, and Social ID.
    Text studentIdTxt(72, 318, "Student's ID: ", fontNext, BLACK, 26);
    Text studentFirstNameTxt(72, 375, "Student's First Name: ", fontNext, BLACK, 26);
    Text studentLastNameTxt(72, 448, "Student's Last Name: ", fontNext, BLACK, 26);
    Text studentGenderTxt(858, 318, "Gender:", fontNext, BLACK, 26);
    Text studentDobTxt(858, 390, "Date Of Birth:", fontNext, BLACK, 26);
    Text studentSocialTxt(858, 464, "Social Id:", fontNext, BLACK, 26);

    InputField csvInput(400, 122, 385, 47, fontNext);
    InputField studentIdInput(411, 302, 385, 47, fontNext);
    InputField studentFirstNameInput(411, 375, 385, 47, fontNext);
    InputField studentLastNameInput(411, 448, 385, 47, fontNext);
    InputField studentGenderInput(1189, 302, 385, 47, fontNext);
    InputField studentDobInput(1189, 375, 385, 47, fontNext);
    InputField studentSocialInput(1189, 448, 385, 47, fontNext);

    Button csvBtn(850, 122, 245, 50, "Submit", fontNext, ORANGE);
    Button byhandBtn(693, 537, 245, 50, "Submit", fontNext, ORANGE);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (csvInput.isSelected()) csvInput.textCursor(csvInput.getInput());
        if (studentIdInput.isSelected()) studentIdInput.textCursor(studentIdInput.getInput());
        if (studentFirstNameInput.isSelected()) studentFirstNameInput.textCursor(studentFirstNameInput.getInput());
        if (studentLastNameInput.isSelected()) studentLastNameInput.textCursor(studentLastNameInput.getInput());
        if (studentGenderInput.isSelected()) studentGenderInput.textCursor(studentGenderInput.getInput());
        if (studentDobInput.isSelected()) studentDobInput.textCursor(studentDobInput.getInput());
        if (studentSocialInput.isSelected()) studentSocialInput.textCursor(studentSocialInput.getInput());

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                csvInput.handleMouseClick(mousePos);
                studentIdInput.handleMouseClick(mousePos);
                studentFirstNameInput.handleMouseClick(mousePos);
                studentLastNameInput.handleMouseClick(mousePos);
                studentGenderInput.handleMouseClick(mousePos);
                studentDobInput.handleMouseClick(mousePos);
                studentSocialInput.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();
                if (byhandBtn.isClicked(mousePos)) {
                    Student temp;
                    temp.basic_info.push_back(oneclass.classID);
                    temp.basic_info.push_back(studentIdInput.getInput());
                    temp.basic_info.push_back(studentFirstNameInput.getInput() + " " + studentLastNameInput.getInput());
                    temp.basic_info.push_back(studentGenderInput.getInput());
                    temp.basic_info.push_back(studentDobInput.getInput());
                    temp.basic_info.push_back(studentSocialInput.getInput());
                    
                    // Use the Student temp to add new student to class
                    popup("Add student success");
                    return;
                }

                if (csvBtn.isClicked(mousePos)) {
                    std::string path = csvInput.getInput();
                    popup("Add student success");
                    return;
                }
            }
            csvInput.processInput(event);
            studentIdInput.processInput(event);
            studentFirstNameInput.processInput(event);
            studentLastNameInput.processInput(event);
            studentGenderInput.processInput(event);
            studentDobInput.processInput(event);
            studentSocialInput.processInput(event);

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        csvTxt.draw(windowNext);
        orTxt.draw(windowNext);
        studentIdTxt.draw(windowNext);
        studentFirstNameTxt.draw(windowNext);
        studentLastNameTxt.draw(windowNext);
        studentGenderTxt.draw(windowNext);
        studentDobTxt.draw(windowNext);
        studentSocialTxt.draw(windowNext);

        csvInput.draw(windowNext);
        studentIdInput.draw(windowNext);
        studentFirstNameInput.draw(windowNext);
        studentLastNameInput.draw(windowNext);
        studentGenderInput.draw(windowNext);
        studentDobInput.draw(windowNext);
        studentSocialInput.draw(windowNext);

        csvBtn.draw(windowNext);
        byhandBtn.draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}
