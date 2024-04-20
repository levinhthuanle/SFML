#include "Activity2.h"

bool Activity2::confirm(std::string content)
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
    Button yesBtn(310.f, 241.f, 60, 45, "Yes", fontNext, RED);
    Button noBtn(230, 241.f, 60, 45, "No", fontNext, GREEN);
    Text text(140, 95, content, fontNext, sf::Color(18, 2, 2), 20);


    while (windowNext.isOpen()) {
        sf::Event event;

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (yesBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return true;
                }
                if (noBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return false;
                }
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        text.draw(windowNext);
        yesBtn.draw(windowNext);
        noBtn.draw(windowNext);

        windowNext.display();

        
    }
    return false;
}

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
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View semester", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture textureNext;
    sf::Font fontNext;
    
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    if (!textureNext.loadFromFile("Assets/ViewCourseStaff.png"))
        std::cout << "Could not load the ViewCourseStaff image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button nextPageBtn(1526.f, 741.f, 92.f, 62.f, "Next", fontNext, sf::Color(218, 110, 50));
    Button prevPageBtn(1526.f, 813.f, 92.f, 62.f, "Prev", fontNext, sf::Color(218, 110, 50));
    

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Button addCourseBtn(1200, 114, 245, 66, "Add course", fontNext, ORANGE);
    Text text(65, 114, semester.getName() + ':', fontNext, GREEN, 36);

    Text dayInfo(120, 150, "Start day: " + semester.startDate.date + "               End day: " + semester.endDate.date, fontNext, GREEN, 36); 

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
                    if (allOfCourse[i].isClicked(mousePos)) {
                        courseInformation(semester, allOfCourse[i].crs);
                        if (allOfCourse[i].crs.getDeletedFlag()) {
                            for (int j = i; j < semester.courses.size()-1; ++j)
                                semester.courses[j] = semester.courses[j + 1];
                            semester.courses.pop_back();
                            for (int j = i; j < semester.courses.size()-1; ++j)
                                allOfCourse[j].update(semester.courses[j]);
                            allOfCourse.pop_back();
                            limitDisplay = (displayFrom + 4) > allOfCourse.size() ? allOfCourse.size() : (displayFrom + 4);
                        }
                        else {
                            semester.courses[i] = allOfCourse[i].crs;
                            allOfCourse[i].update(semester.courses[i]);
                        }
                    }
                }

                if (addCourseBtn.isClicked(mousePos)) {
                    addCourse(semester);
                    
                    int i = semester.courses.size() - 1;
                    if (i > -1)
                    {
                        courseButton temp(65 + 273 * (i % 5), 209 + 210 * (i / 5), semester.courses[i], fontNext);
                        allOfCourse.push_back(temp);
                    }
                }
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        text.draw(windowNext);
        for (int i = displayFrom; i < displayFrom + min(allOfCourse.size() - displayFrom, limitDisplay); i++) {
            allOfCourse[i].draw(windowNext);
        }
        dayInfo.draw(windowNext);
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
    Text numberCreditTxt(858, 218, "Credits:", fontNext, BLACK, 26);
    Text maxStudentTxt(858, 290, "Max Student:", fontNext, BLACK, 26);
    Text dayTxt(858, 364, "Days in a week", fontNext, BLACK, 26);
    Text csvTxt(72, 110, "Path to the list of students enroled in the course:", fontNext, GREEN, 26);
    

    InputField courseIdInput(411, 202, 385, 47, fontNext);
    InputField courseNameInput(411, 275, 385, 47, fontNext);
    InputField teacherNameInput(411, 348, 385, 47, fontNext);
    InputField sessionInput(411, 421, 385, 47, fontNext);
    InputField numberCreditInput(1189, 202, 385, 47, fontNext);
    InputField maxStudentInput(1189, 275, 385, 47, fontNext);
    InputField dayInput(1189, 348, 385, 47, fontNext);
    InputField csvInput(650, 105, 555, 47, fontNext);

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
        if (csvInput.isSelected()) csvInput.textCursor(csvInput.getInput());


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
                csvInput.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (submitBtn.isClicked(mousePos)) {
                    Course newCourse(semester.getPath(), courseIdInput.getInput(), courseNameInput.getInput(), teacherNameInput.getInput(), std::stoi(numberCreditInput.getInput()), std::stoi(maxStudentInput.getInput()), dayInput.getInput(), sessionInput.getInput());
                    semester.addCourse(newCourse);
                    windowNext.close();
                }
            }
            courseIdInput.processInput(event);
            courseNameInput.processInput(event);
            teacherNameInput.processInput(event);
            sessionInput.processInput(event);
            numberCreditInput.processInput(event);
            maxStudentInput.processInput(event);
            dayInput.processInput(event);
            csvInput.processInput(event);


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
        csvTxt.draw(windowNext);

        courseIdInput.draw(windowNext);
        courseNameInput.draw(windowNext);
        teacherNameInput.draw(windowNext);
        sessionInput.draw(windowNext);
        numberCreditInput.draw(windowNext);
        maxStudentInput.draw(windowNext);
        dayInput.draw(windowNext);
        csvInput.draw(windowNext);

        submitBtn.draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

void Activity2::courseInformation(Semester& semester, Course& course)
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
    Text courseIdTxt(47, 107, "Course Id: " + course.getID(), fontNext, BLACK, 26);
    Text courseNameTxt(47, 137, "Course Name: " + course.getName(), fontNext, BLACK, 26);
    Text teacherNameTxt(47, 167, "Teacher name: " + course.getTeacher(), fontNext, BLACK, 26);
    Text sessionTxt(47, 197, "Session: " + course.getSession(), fontNext, BLACK, 26);
    Text creditTxt(721, 107, "Number of credits: " + std::to_string(course.getCredit()), fontNext, BLACK, 26);
    Text maxStudentTxt(721, 137, "Max students: " + std::to_string(course.getMaxStu()), fontNext, BLACK, 26);
    Text curStudentTxt(721, 167, "Current students: " + std::to_string(course.getCurStu()), fontNext, BLACK, 26);
    Text dayTxt(721, 197, "Day: " + course.getDay(), fontNext, BLACK, 26);

    Button deleteCourseBtn(1305, 100, 300, 54, "Delete this course", fontNext, RED);
    Button updateCourseBtn(1305, 179, 300, 54, "Update information", fontNext, RED);
    Button studentListBtn(1305, 258, 300, 54, "Student list", fontNext, RED);

    while (windowNext.isOpen()) {
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (deleteCourseBtn.isClicked(mousePos)) {
                    if (confirm("Do you really want to delete this course?")) {
                        semester.removeCourse(course);
                        popup("This course has been deleted");
                        return;
                    }
                }

                if (updateCourseBtn.isClicked(mousePos)) {
                    updateCourseInformation(course);
                    windowNext.close();
                }

                if (studentListBtn.isClicked(mousePos)) {
                    viewCourseStudentList(course);
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        goBackBtn.draw(windowNext);
        deleteCourseBtn.draw(windowNext);
        updateCourseBtn.draw(windowNext);
        studentListBtn.draw(windowNext);

        courseIdTxt.draw(windowNext);
        courseNameTxt.draw(windowNext);
        teacherNameTxt.draw(windowNext);
        sessionTxt.draw(windowNext);
        creditTxt.draw(windowNext);
        maxStudentTxt.draw(windowNext);
        curStudentTxt.draw(windowNext);
        dayTxt.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::updateCourseInformation(Course& course)
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

    Button goBackBtn(519, 766, 245, 66, "Go back", fontNext, ORANGE);
    Button acceptBtn(919, 766, 245, 66, "Accept", fontNext, RED);

    Text courseNameTxt(72, 218, "Course name: ", fontNext, BLACK, 26);
    Text teacherNameTxt(72, 275, "Teacher Name: ", fontNext, BLACK, 26);
    Text sessionTxt(72, 348, "Session:", fontNext, BLACK, 26);
    Text numberCreditTxt(858, 218, "Credits:", fontNext, BLACK, 26);
    Text maxStudentTxt(858, 290, "Max Student:", fontNext, BLACK, 26);
    Text dayTxt(858, 364, "Days in a week", fontNext, BLACK, 26);

    InputField courseNameInput(411, 202, 385, 47, fontNext); courseNameInput.input = course.getName();
    InputField teacherNameInput(411, 275, 385, 47, fontNext); teacherNameInput.input = course.getTeacher();
    InputField sessionInput(411, 348, 385, 47, fontNext); sessionInput.input = course.getSession();
    InputField numberCreditInput(1189, 202, 385, 47, fontNext); numberCreditInput.input = std::to_string(course.getCredit());
    InputField maxStudentInput(1189, 275, 385, 47, fontNext); maxStudentInput.input = std::to_string(course.getMaxStu());
    InputField dayInput(1189, 348, 385, 47, fontNext); dayInput.input = course.getDay();

    while (windowNext.isOpen()) {
        sf::Event event;
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

                courseNameInput.handleMouseClick(mousePos);
                teacherNameInput.handleMouseClick(mousePos);
                sessionInput.handleMouseClick(mousePos);
                numberCreditInput.handleMouseClick(mousePos);
                maxStudentInput.handleMouseClick(mousePos);
                dayInput.handleMouseClick(mousePos);
                

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (acceptBtn.isClicked(mousePos)) {
                    course.setName(courseNameInput.getInput());
                    course.setTeacher(teacherNameInput.getInput());
                    course.setSession(sessionInput.getInput());
                    course.setCredit(std::stoi(numberCreditInput.getInput()));
                    course.setMaxStu(std::stoi(maxStudentInput.getInput()));
                    course.setDay(dayInput.getInput());

                    course.submitInfoChange();

                    popup("Succesful change the information of the course");
                    windowNext.close();
                    return;
                }

            }
            courseNameInput.processInput(event);
            teacherNameInput.processInput(event);
            sessionInput.processInput(event);
            numberCreditInput.processInput(event);
            maxStudentInput.processInput(event);
            dayInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        goBackBtn.draw(windowNext);
        acceptBtn.draw(windowNext);

        courseNameTxt.draw(windowNext);
        teacherNameTxt.draw(windowNext);
        sessionTxt.draw(windowNext);
        numberCreditTxt.draw(windowNext);
        maxStudentTxt.draw(windowNext);
        dayTxt.draw(windowNext);

        courseNameInput.draw(windowNext);
        teacherNameInput.draw(windowNext);
        sessionInput.draw(windowNext);
        numberCreditInput.draw(windowNext);
        maxStudentInput.draw(windowNext);
        dayInput.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::viewCourseStudentList(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Course's Student List", sf::Style::Close | sf::Style::Titlebar);
    std::cout << course.getID() << std::endl;

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewOneClassStaff.png"))
        std::cout << "Could not load the ViewOneClassStaff image" << std::endl;
    std::cout << "Generate View Course's Student List sucess" << std::endl;
    sf::Sprite background(textureNext);

    const sf::Color BLACK = sf::Color(18, 2, 2);
    const sf::Color GREEN = sf::Color(26, 114, 98);
    const sf::Color RED = sf::Color(144, 44, 44);
    const sf::Color ORANGE = sf::Color(218, 110, 50);
    Text no(82, 136, "No", fontNext, GREEN, 32);
    Text studentID(152, 136, "Student's ID", fontNext, GREEN, 32);
    Text studentName(536, 136, "Student's Name", fontNext, GREEN, 32);
    Text gender(1050, 136, "Class", fontNext, GREEN, 32);
    Button line1(82, 174, 1133, 0, "", fontNext, BLACK);
    Button line2(135, 136, 0, 630, "", fontNext, BLACK);
    Button line3(513, 136, 0, 630, "", fontNext, BLACK);
    Button line4(1044, 136, 0, 630, "", fontNext, BLACK);

    Button addStudentBtn(1420.f, 117.f, 240, 50.f, "Add student", fontNext, RED);
    Button removeStudentBtn(1420.f, 191.f, 240.f, 50.f, "Remove Student", fontNext, RED);
    Button importListBtn(1420, 260, 240, 50, "Import list ", fontNext, RED);
    Button exportListBtn(1420, 330, 240, 50, "Export List ", fontNext, RED);
    Button importScoreBoardBtn(1420, 400, 240, 50, "Import ScoreBoard ", fontNext, RED);
    vector<Text> listOfStudent;

    vector<Student> list = course.getStudiedStudent();

    for (int i = 0; i < list.size(); i++) {
        std::string temp = std::to_string(i + 1) + "    ";
        if (temp.size() == 5)
            temp = '0' + temp;

        temp = temp + list[i].getID() + "                           ";
        temp += list[i].getFullname();
        for (int j = 1; j <= 47 - list[i].getFullname().size(); j++)
            temp += ' ';
        temp += list[i].getClass();

        Text text(82.f, 188.f + 32 * i, temp, fontNext, BLACK, 32);

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

                //if (removeStudentBtn.isClicked(mousePos))
                //    removeStudent(oneclass);

                //if (addStudentBtn.isClicked(mousePos))
                //    addStudent(oneclass);

                //if (exportListBtn.isClicked(mousePos)) {
                //    popup("Export the list of student succes");
                //}

                //if (scoreBoardBtn.isClicked(mousePos)) {
                //    scoreBoardOfClassStaff(oneclass);
                }
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
        importListBtn.draw(windowNext);
        exportListBtn.draw(windowNext);
        importScoreBoardBtn.draw(windowNext);

        for (int i = 0; i < listOfStudent.size(); i++)
            listOfStudent[i].draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
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

    Button addStudentBtn(1420.f, 117.f, 240, 50.f, "Add student", fontNext, RED);
    Button removeStudentBtn(1420.f, 191.f, 240.f, 50.f, "Remove Student", fontNext, RED);
    //Button exportListBtn(1420, 260, 240, 50, "Export list ", fontNext, RED);
    //Button scoreBoardBtn(1420, 330, 240, 50, "ScoreBoard ", fontNext, RED);
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
                {
                    int before = oneclass.students.size();
                    removeStudent(oneclass);
                    int after = oneclass.students.size();
                    if (before != after)
                    {
                        listOfStudent.clear(); 
                        for (int i = 0; i < oneclass.students.size(); i++) {
                            std::string temp = std::to_string(i + 1) + "    ";
                            if (temp.size() == 5)
                                temp = '0' + temp;

                            temp = temp + oneclass.students[i].getID() + "                           ";
                            temp += oneclass.students[i].getFullname();
                            for (int j = 1; j <= 47 - oneclass.students[i].getFullname().size(); j++)
                                temp += ' ';
                            temp += oneclass.students[i].getGender();

                            Text text(82.f, 188.f + 32 * i, temp, fontNext, BLACK, 32);

                            listOfStudent.push_back(text);
                        }
                    }
            
                }

                if (addStudentBtn.isClicked(mousePos))
                {
                    int before = oneclass.students.size(); 
                    addStudent(oneclass);

                    int after = oneclass.students.size(); 
                    if (before != after)
                    {
                        int i = after - 1;
                        std::string temp = std::to_string(i + 1) + "    ";
                        if (temp.size() == 5)
                            temp = '0' + temp;

                        temp = temp + oneclass.students[i].getID() + "                           ";
                        temp += oneclass.students[i].getFullname();
                        for (int j = 1; j <= 47 - oneclass.students[i].getFullname().size(); j++)
                            temp += ' ';
                        temp += oneclass.students[i].getGender();

                        Text text(82.f, 188.f + 32 * i, temp, fontNext, BLACK, 32);
                        listOfStudent.push_back(text);
                    }
                }

               /* if (exportListBtn.isClicked(mousePos)) {

                    popup("Export the list of student succes");
                }*/

                /*if (scoreBoardBtn.isClicked(mousePos)) {
                    scoreBoardOfClassStaff(oneclass);
                }*/
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
        //exportListBtn.draw(windowNext);
        //scoreBoardBtn.draw(windowNext);

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
    Text classID(480, 131, oneclasss.classID, fontNext, sf::Color(26, 114, 98), 36); 
    InputField enterSYinput(620, 131, 454, 66, fontNext);
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
                    std::string classID = oneclasss.classID + enterSYinput.getInput(); 
                    if (classID.size() == 9)
                    {
                        Student temp(classID); 
                        if (temp.is_exist())
                        {
                            temp.self_destroy();
                            oneclasss = Class(oneclasss.classID); 
                            popup("Remove succesful");
                            windowNext.close();
                        }
                        else popup("Can not find this student."); 
                    }
                    else popup("Invalid ID"); 
                }
            }
            enterSYinput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        enterSYinput.draw(windowNext);
        enterSYtxt.draw(windowNext);
        classID.draw(windowNext); 
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
    Text classID(380, 302, oneclass.classID, fontNext, BLACK, 26); 

    InputField csvInput(400, 122, 385, 47, fontNext);
    InputField studentIdInput(500, 302, 285, 47, fontNext);
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
                    vector<std::string> temp_basic_info; 

                    temp_basic_info.push_back(oneclass.classID);
                    
                    if (studentIdInput.getInput().size() == 3) 
                        temp_basic_info.push_back(oneclass.classID + studentIdInput.getInput());
                    if (studentFirstNameInput.getInput().size() != 0 && studentLastNameInput.getInput().size() != 0)
                        temp_basic_info.push_back(studentFirstNameInput.getInput() + " " + studentLastNameInput.getInput());
                    std::string gender = studentGenderInput.getInput();
                    std::transform(gender.begin(), gender.begin(), gender.end(),
                        [](unsigned char c) {return std::tolower(c); }); 
                    if( gender == "male" || gender == "female") 
                        temp_basic_info.push_back(gender);
                    Date dob(studentDobInput.getInput());
                    if (dob.is_valid()) 
                        temp_basic_info.push_back(studentDobInput.getInput());
                    temp_basic_info.push_back(studentSocialInput.getInput());
                    
                    if (temp_basic_info.size() != 6)
                        popup("Wrong input or missing element.");
                    else
                    {
                        Student temp(temp_basic_info);
                        if (!temp.is_exist())
                        {
                            temp.create();
                            oneclass.students.push_back(temp);
                            // Use the Student temp to add new student to class
                            popup("Add student success");
                            windowNext.close();
                        }
                        else popup("This ID of this student is existed."); 
                    }
                   
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
        classID.draw(windowNext);

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

void Activity2::scoreBoardOfClassStaff(Class& oneclass)
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
