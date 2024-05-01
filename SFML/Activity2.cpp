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
    Text text(100, 95, content, fontNext, sf::Color(18, 2, 2), 20);

    
    while (windowNext.isOpen()) {
        sf::Event event;

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::KeyPressed) {
                if (event.text.unicode == '\r') windowNext.close();
            }
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

int Activity2::drawScoreBoard(Course& course, sf::RenderWindow& window, sf::Font& font, int displayFrom, int displayLimit)
{
    //Button horizontalLine(22, 273, 1545, 0, "", fontNext, BLACK);
    //Button verticalLine1(82, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine2(309, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine3(519, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine4(859, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine5(1000, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine6(1159, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine7(1266, 239, 0, 452, "", fontNext, BLACK);
    //Button verticalLine8(1372, 239, 0, 452, "", fontNext, BLACK);

    //Text noTxt(29, 232, "No", fontNext, GREEN, 32);
    //Text studentNameTxt(103, 232, "Student's ID", fontNext, GREEN, 32);
    //Text studentIdTxt(316, 232, "Class", fontNext, GREEN, 32);
    //Text midtermTxt(529, 232, "Fullname", fontNext, GREEN, 32);
    //Text finalTxt(862, 232, "Practice", fontNext, GREEN, 32);
    //Text extraTxt(1002, 232, "Midterm", fontNext, GREEN, 32);
    //Text overallTxt(1167, 232, "Final", fontNext, GREEN, 32);
    //Text exTxt(1287, 232, "Plus", fontNext, GREEN, 32);
    //Text ex1Txt(1420, 232, "Overall", fontNext, GREEN, 32);

    //vector<Text> studentInformation;
    //vector<Button> studentInforListBtn;
    //for (int i = 1; i < course.score.size() ; i++) {
    //    std::string noStr =(i < 10) ? ('0' + std::to_string(i)) : (std::to_string(i));
    //    Text numTxt(37, (float)280 + 36 * ((i-1) % 10), noStr, fontNext, GREEN, 32);

    //    Text sIdTxt(105,(float) (280 + 36 * ((i-1) % 10)), course.score[i][0], fontNext, RED, 32);
    //    Text sCTxt(323, (float)280 + 36 * ((i-1) % 10), course.score[i][1], fontNext, BLACK, 32);
    //    Text sFTxt(525, (float)280 + 36 * ((i-1) % 10), course.score[i][2], fontNext, BLACK, 32);
    //    Text pracTxt(888, (float)280 + 36 * ((i-1) % 10), course.score[i][3], fontNext, BLACK, 32);
    //    Text midTxt(1037, (float)280 + 36 * ((i-1) % 10), course.score[i][4], fontNext, BLACK, 32);
    //    Text finTxt(1185, (float)280 + 36 * ((i-1) % 10), course.score[i][5], fontNext, BLACK, 32);
    //    Text plusTxt(1291, (float)280 + 36 * ((i-1) % 10), course.score[i][6], fontNext, BLACK, 32);
    //    Text overTxt(1437, (float)280 + 36 * ((i-1) % 10), course.score[i][7], fontNext, RED, 32);

    //    studentInformation.push_back(numTxt);
    //    studentInformation.push_back(sIdTxt);
    //    studentInformation.push_back(sCTxt);
    //    studentInformation.push_back(sFTxt);
    //    studentInformation.push_back(pracTxt);
    //    studentInformation.push_back(midTxt);
    //    studentInformation.push_back(finTxt);
    //    studentInformation.push_back(plusTxt);
    //    studentInformation.push_back(overTxt);

    //    Button tmpBtn(105, (float)(280 + 36 * ((i - 1) % 10)), 180, 32, "23125019",fontNext, BLACK);
    //    studentInforListBtn.push_back(tmpBtn);
    //}



    //horizontalLine.draw(windowNext);
    //verticalLine1.draw(windowNext);
    //verticalLine2.draw(windowNext);
    //verticalLine3.draw(windowNext);
    //verticalLine4.draw(windowNext);
    //verticalLine5.draw(windowNext);
    //verticalLine6.draw(windowNext);
    //verticalLine7.draw(windowNext);
    //verticalLine8.draw(windowNext);

    //noTxt.draw(windowNext);
    //studentNameTxt.draw(windowNext);
    //studentIdTxt.draw(windowNext);
    //midtermTxt.draw(windowNext);
    //finalTxt.draw(windowNext);
    //extraTxt.draw(windowNext);
    //overallTxt.draw(windowNext);
    //exTxt.draw(windowNext);
    //ex1Txt.draw(windowNext);

    //for (int i = displayFrom * 9; i < displayLimit * 9; i++)
    //    studentInformation[i].draw(windowNext);


    //return studentInformation.size() / 9;
    return 1;
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
           
            std::string message = "This course is not be score!";
            Text uncompleted(110, 382, message, fontNext, ORANGE, 26);
            
            uncompleted.draw(windowNext);
        }
        else {
            Text typeOfScorse(110, 425, "Midterm\t Practice\t Plus\t Other\t Final\t Overall", fontNext, GREEN, textSize);
            std::string Score = '\t' + subject.midScore + "\t\t          " + subject.practiceScore + "\t\t    ";
            Score += subject.plusScore + "\t\t    " + subject.otherScore + "\t\t  ";
            Score += subject.finalScore + "\t\t      " + subject.aveScore;
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

void Activity2::createNewSchoolYearStaff(vector<SchoolYear>& existedSchoolYear)
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
    Text enterSYtxt(120.f, 137.f, "Enter start year:", fontNext, sf::Color(26, 114, 98), 36);
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
                    std::string currYear = enterSYinput.getInput(); 
                    for (int c = 0; c < currYear.size(); ++c)
                    {
                        if (currYear[c] > '9' || currYear[c] < '0')
                        {
                            popup("Wrong year format. Try again."); 
                            break; 
                        }
                        if (c == currYear.size() - 1) {
                            if (currYear.size() >= 2)
                                currYear = currYear.substr(currYear.size() - 2, currYear.size()-1);
                            SchoolYear firstSchoolYear(currYear + '-' + std::to_string(stol(currYear) + 1));
                            firstSchoolYear.createNewSchoolYear();
                            existedSchoolYear.push_back(firstSchoolYear);
                            popup("School year " + currYear + "_" + currYear[0] + (char)(currYear[1] + 1) + " created");
                            windowNext.close();
                        }
                    }
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

void Activity2::viewAllCourseStaff(vector<SchoolYear>& schoolyear)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "All Course", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewAllCourseStaff.png"))
        std::cout << "Could not load the YourCourseStudent image" << std::endl;
    std::cout << "Generate View all course sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button nextPageBtn(1587.f, 753.f, 92.f, 62.f, "Next", fontNext, ORANGE);
    Button prevPageBtn(1587.f, 815.f, 92.f, 62.f, "Prev", fontNext, ORANGE);
    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    vector<Text> allOfCourse;


    vector<allCourseMenu> allCourseMenuBtn;
    for (int i = 0; i < schoolyear.size(); i++) {
        allCourseMenu temp(40,(float) (90 + 230 * (i % 3)), schoolyear[i], fontNext);
        allCourseMenuBtn.push_back(temp);
    }
    int displayFrom = 0;

    while (windowNext.isOpen()) {
        long long displayLimit = (displayFrom + 3) > allCourseMenuBtn.size() ? allCourseMenuBtn.size() : (displayFrom + 3);
        sf::Event event;
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + 3 <= allCourseMenuBtn.size())
                        displayFrom += 3;
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - 3 >= 0)
                        displayFrom -= 3;
                }

                for (int i = displayFrom; i < displayLimit; i++) {
                    for (int j = 0; j < allCourseMenuBtn[i].listCoursesBtn1.size(); j++) {
                        if (allCourseMenuBtn[i].listCoursesBtn1[j].isClicked(mousePos)) {
                            courseInformation(schoolyear[i].semester[0], schoolyear[i].semester[0].courses[j]);
                            return;
                        }
                    }

                    for (int j = 0; j < allCourseMenuBtn[i].listCoursesBtn2.size(); j++) {
                        if (allCourseMenuBtn[i].listCoursesBtn2[j].isClicked(mousePos)) {
                            courseInformation(schoolyear[i].semester[1], schoolyear[i].semester[1].courses[j]);
                            return;
                        }
                    }

                    for (int j = 0; j < allCourseMenuBtn[i].listCoursesBtn3.size(); j++) {
                        if (allCourseMenuBtn[i].listCoursesBtn3[j].isClicked(mousePos)) {
                            courseInformation(schoolyear[i].semester[2], schoolyear[i].semester[2].courses[j]);
                            return;
                        }
                    }
                }
            }

        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        for (int i = displayFrom; i < displayLimit; i++) {
            allCourseMenuBtn[i].draw(windowNext);
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
        courseButton temp((float)65 + 273*(i % 5), (float)209 + 210 * (i/5), semester.courses[i], fontNext);
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
                    long long i = semester.courses.size() - 1;

                    if (i > -1)
                    {
                        courseButton temp((float)(65 + 273 * (i % 5)),(float) (209 + 210 * (i / 5)), semester.courses[i], fontNext);
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
    if (!textureNext.loadFromFile("Assets/CourseInformationStaff.png"))
        std::cout << "Could not load the Course information image" << std::endl;
    std::cout << "Generate The course information sucess" << std::endl;
    sf::Sprite background(textureNext);

    
    Text courseIdTxt(47, 107, "Course Id: " + course.getID(), fontNext, BLACK, 26);
    Text courseNameTxt(47, 137, "Course Name: " + course.getName(), fontNext, BLACK, 26);
    Text teacherNameTxt(47, 167, "Teacher: " + course.getTeacher(), fontNext, BLACK, 26);
    Text sessionTxt(47, 197, "Session: " + course.getSession(), fontNext, BLACK, 26);
    Text creditTxt(721, 107, "Credits: " + std::to_string(course.getCredit()), fontNext, BLACK, 26);
    Text maxStudentTxt(721, 137, "Max students: " + std::to_string(course.getMaxStu()), fontNext, BLACK, 26);
    Text curStudentTxt(721, 167, "Current students: " + std::to_string(course.getCurStu()), fontNext, BLACK, 26);
    Text dayTxt(721, 197, "Day: " + course.getDay(), fontNext, BLACK, 26);


    Button goBackBtn(686, 820, 245, 66, "Go back", fontNext, ORANGE);
    Button deleteCourseBtn(1280, 96, 270, 40, "Delete this course", fontNext, RED);
    Button updateCourseBtn(990, 96, 240, 40, "Update information", fontNext, RED);
    Button importScoreBtn(718, 723, 265, 50, "Import Scoreboard", fontNext, RED);
    Button addStudentBtn(13, 724, 179, 50, "Add student", fontNext, RED);
    Button importStudentListBtn(205, 724, 257, 50, "Import student list", fontNext, RED);
    Button removeStudentBtn(476, 724, 229, 50, "Remove student", fontNext, RED);
    Button exportStudentListBtn(995, 724, 267, 50, "Export Student List", fontNext, RED);
    Button exportScoreBoardBtn(1276, 724, 267, 50, "Export Scoreboard", fontNext, RED);
    Button nextPageBtn(1586.f, 736.f, 92.f, 62.f, "Next", fontNext, sf::Color(218, 110, 50));
    Button prevPageBtn(1586.f, 813.f, 92.f, 62.f, "Prev", fontNext, sf::Color(218, 110, 50));
       
    Button horizontalLine(22, 273, 1545, 0, "", fontNext, BLACK);
    Button verticalLine1(82, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine2(309, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine3(519, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine4(859, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine5(1000, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine6(1159, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine7(1266, 239, 0, 452, "", fontNext, BLACK);
    Button verticalLine8(1372, 239, 0, 452, "", fontNext, BLACK);

    Text noTxt(29, 232, "No", fontNext, GREEN, 32);
    Text studentNameTxt(103, 232, "Student's ID", fontNext, GREEN, 32);
    Text studentIdTxt(316, 232, "Class", fontNext, GREEN, 32);
    Text midtermTxt(529, 232, "Fullname", fontNext, GREEN, 32);
    Text finalTxt(862, 232, "Practice", fontNext, GREEN, 32);
    Text extraTxt(1002, 232, "Midterm", fontNext, GREEN, 32);
    Text overallTxt(1167, 232, "Final", fontNext, GREEN, 32);
    Text exTxt(1287, 232, "Plus", fontNext, GREEN, 32);
    Text ex1Txt(1420, 232, "Overall", fontNext, GREEN, 32);

    vector<Text> studentInformation;
    vector<Button> studentInforListBtn;
    for (int i = 1; i < course.score.size(); i++) {
        std::string noStr = (i < 10) ? ('0' + std::to_string(i)) : (std::to_string(i));
        Text numTxt(37, (float)280 + 36 * ((i - 1) % 10), noStr, fontNext, GREEN, 32);

        Text sIdTxt(105, (float)(280 + 36 * ((i - 1) % 10)), course.score[i][0], fontNext, RED, 32);
        Text sCTxt(323, (float)280 + 36 * ((i - 1) % 10), course.score[i][1], fontNext, BLACK, 32);
        Text sFTxt(525, (float)280 + 36 * ((i - 1) % 10), course.score[i][2], fontNext, BLACK, 32);
        Text pracTxt(888, (float)280 + 36 * ((i - 1) % 10), course.score[i][3], fontNext, BLACK, 32);
        Text midTxt(1037, (float)280 + 36 * ((i - 1) % 10), course.score[i][4], fontNext, BLACK, 32);
        Text finTxt(1185, (float)280 + 36 * ((i - 1) % 10), course.score[i][5], fontNext, BLACK, 32);
        Text plusTxt(1291, (float)280 + 36 * ((i - 1) % 10), course.score[i][6], fontNext, BLACK, 32);
        Text overTxt(1437, (float)280 + 36 * ((i - 1) % 10), course.score[i][7], fontNext, RED, 32);

        studentInformation.push_back(numTxt);
        studentInformation.push_back(sIdTxt);
        studentInformation.push_back(sCTxt);
        studentInformation.push_back(sFTxt);
        studentInformation.push_back(pracTxt);
        studentInformation.push_back(midTxt);
        studentInformation.push_back(finTxt);
        studentInformation.push_back(plusTxt);
        studentInformation.push_back(overTxt);

        Button tmpBtn(105, (float)(280 + 36 * ((i - 1) % 10)), 180, 32, "23125019", fontNext, BLACK);
        studentInforListBtn.push_back(tmpBtn);
    }

    int displayFrom = 0, displayLimit = 0;

    while (windowNext.isOpen()) {
        sf::Event event;
        long long displayLimit = (displayFrom + 10) > studentInformation.size()/9 ? studentInformation.size()/9 : (displayFrom + 10);
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return;
                }

                if (deleteCourseBtn.isClicked(mousePos)) {
                    if (confirm("Do you really want to delete this course?")) {
                        semester.removeCourse(course);
                        popup("This course has been deleted");
                        return;
                    }
                }

                if (updateCourseBtn.isClicked(mousePos)) {
                    updateCourseInformation(course);
                    courseIdTxt.setString("Course Id: " + course.getID());
                    courseNameTxt.setString("Course Name: " + course.getName());
                    teacherNameTxt.setString("Teacher: " + course.getTeacher());
                    sessionTxt.setString("Session: " + course.getSession());
                    creditTxt.setString("Credits: " + std::to_string(course.getCredit()));
                    maxStudentTxt.setString("Max students: " + std::to_string(course.getMaxStu()));
                    curStudentTxt.setString("Current students: " + std::to_string(course.getCurStu()));
                    dayTxt.setString("Day: " + course.getDay());
                }

                if (importScoreBtn.isClicked(mousePos)) {
                    importScoreCourseStaff(semester, course);
                    curStudentTxt.setString("Current students: " + std::to_string(course.getCurStu()));
                    break;
                }

                if (addStudentBtn.isClicked(mousePos)) {
                    addStudentToCourse(course);
                    curStudentTxt.setString("Current students: " + std::to_string(course.getCurStu()));
                    break;
                }

                if (removeStudentBtn.isClicked(mousePos)) {
                    removeStudentFromCourse(course);
                    curStudentTxt.setString("Current students: " + std::to_string(course.getCurStu()));
                    break;
                }

                if (importStudentListBtn.isClicked(mousePos)) {
                    importStudentList(course);
                    curStudentTxt.setString("Current students: " + std::to_string(course.getCurStu()));
                    break;
                }

                if (exportStudentListBtn.isClicked(mousePos)) {
                    exportStudentList(course);
                    break;
                }

                if (exportScoreBoardBtn.isClicked(mousePos)) {
                    exportScoreBoard(course);
                    break;
                }

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + 10 <= displayLimit)
                        displayFrom += 10;
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - 10 >= 0)
                        displayFrom -= 10;
                }

                for (int i = displayFrom; i < displayLimit; i++) 
                    if (studentInforListBtn[i].isClicked(mousePos)){
                        changeStudentScore(course.score[i + 1]);
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        goBackBtn.draw(windowNext);
        deleteCourseBtn.draw(windowNext);
        updateCourseBtn.draw(windowNext);
        addStudentBtn.draw(windowNext);
        importStudentListBtn.draw(windowNext);
        removeStudentBtn.draw(windowNext);
        importScoreBtn.draw(windowNext);
        exportStudentListBtn.draw(windowNext);
        exportScoreBoardBtn.draw(windowNext);

        courseIdTxt.draw(windowNext);
        courseNameTxt.draw(windowNext);
        teacherNameTxt.draw(windowNext);
        sessionTxt.draw(windowNext);
        creditTxt.draw(windowNext);
        maxStudentTxt.draw(windowNext);
        curStudentTxt.draw(windowNext);
        dayTxt.draw(windowNext);
        horizontalLine.draw(windowNext);
        verticalLine1.draw(windowNext);
        verticalLine2.draw(windowNext);
        verticalLine3.draw(windowNext);
        verticalLine4.draw(windowNext);
        verticalLine5.draw(windowNext);
        verticalLine6.draw(windowNext);
        verticalLine7.draw(windowNext);
        verticalLine8.draw(windowNext);

        noTxt.draw(windowNext);
        studentNameTxt.draw(windowNext);
        studentIdTxt.draw(windowNext);
        midtermTxt.draw(windowNext);
        finalTxt.draw(windowNext);
        extraTxt.draw(windowNext);
        overallTxt.draw(windowNext);
        exTxt.draw(windowNext);
        ex1Txt.draw(windowNext);

        for (int i = displayFrom * 9; i < displayLimit * 9; i++)
            studentInformation[i].draw(windowNext);
        

        windowNext.display();
    }
}

void Activity2::addStudentToCourse(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Add student", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/FindStudentID.png"))
        std::cout << "Could not load the Course information image" << std::endl;
    std::cout << "Generate The Enter Student ID sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField studentIdInput(351.f, 98.f, 382.f, 39.f, fontNext);
    Button submitBtn(351, 170, 150, 39, "Submit", fontNext, RED);

    studentIdInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (studentIdInput.isSelected()) studentIdInput.textCursor(studentIdInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                studentIdInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!studentIdInput.getInput().empty()) {
                        std::string ID;
                        ID = studentIdInput.getInput();
                        if (ID.size() != 9) {
                            popup("Student not found");
                            continue;
                        }
                        for (int i = 0; i < course.score.size(); ++i) {
                            if (course.score[i][0] == ID) {
                                popup("Student already in course");
                                continue;
                            }
                        }
                        std::string clss = ID.substr(0, 6);
                        std::string order = ID.substr(6);	
                        fsys::path studentPath = "data/student";
                        studentPath /= clss + "/" + order;
                        if (!fsys::exists(studentPath))
                            popup("Student not found");
                        else {
                            Student stu(ID);
                            course.addStudent(stu);
                            popup("Student added into course");
                            windowNext.close();
                            return;
                        }  
                    }
                }
            }
            studentIdInput.processInput(event);
            if (studentIdInput.chooseNextField()) {
                if (!studentIdInput.getInput().empty()) {
                    std::string ID = studentIdInput.getInput();
                    if (ID.size() != 9) {
                        popup("Student not found");
                        continue;
                    }
                    std::string clss = ID.substr(0, 6);
                    std::string order = ID.substr(6);
                    fsys::path studentPath = "data/student";
                    studentPath /= clss + "/" + order;
                    if (!fsys::exists(studentPath))
                        popup("Student not found");
                    else {
                        Student stu(ID);
                        course.addStudent(stu);
                        popup("Student added into course");
                        windowNext.close();
                        return;
                    }
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        studentIdInput.draw(windowNext);
        submitBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::importStudentList(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Import student list", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/importFile.png"))
        std::cout << "Could not load the File Selection image" << std::endl;
    std::cout << "Generate The Import List File sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField pathInput(151, 98, 695, 39, fontNext);
    Button browseBtn(151, 164, 150, 39, "Browse", fontNext, RED);    
    Button submitBtn(331, 164, 150, 39, "Submit", fontNext, RED);

    pathInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (pathInput.isSelected()) pathInput.textCursor(pathInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                pathInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!pathInput.getInput().empty()) {
                        if (!fsys::exists(pathInput.getInput())) {
                            popup("File not found");
                            break;
                        }
                        if (course.importStudentsFile(pathInput.getInput()))
                            popup("Student list imported");
                        else popup("Error processing import student list file");
                        return;
                    }
                }
                if (browseBtn.isClicked(mousePos)) {
                    std::string path(tinyfd_openFileDialog(0, 0, 0, 0, 0, 0));
                    if (course.importStudentsFile(path))
                        popup("Student list imported");
                    else popup("Error processing import student list file");
                    return;
                }
            }
            pathInput.processInput(event);
            if (pathInput.chooseNextField()) {
                if (!pathInput.getInput().empty()) {
                    if (!fsys::exists(pathInput.getInput())) {
                        popup("File not found");
                        break;
                    }
                    if (course.importStudentsFile(pathInput.getInput()))
                        popup("Student list imported");
                    else popup("Error processing import student list file");
                    return;
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        pathInput.draw(windowNext);
        browseBtn.draw(windowNext);
        submitBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::removeStudentFromCourse(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Remove student", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/FindStudentID.png"))
        std::cout << "Could not load the Find Student image" << std::endl;
    std::cout << "Generate The Enter Student ID sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField studentIdInput(351.f, 98.f, 382.f, 39.f, fontNext);
    Button submitBtn(351, 170, 150, 39, "Submit", fontNext, RED);

    studentIdInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (studentIdInput.isSelected()) studentIdInput.textCursor(studentIdInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                studentIdInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!studentIdInput.getInput().empty()) {
                        std::string ID = studentIdInput.getInput();
                        if (ID.size() != 9) {
                            popup("Student not found");
                            continue;
                        }
                        if (!course.removeStudent(ID))
                            popup("Student not found");
                        else {
                            popup("Student removed from course");
                            return;
                        }
                    }
                }
            }
            studentIdInput.processInput(event);
            if (studentIdInput.chooseNextField()) {
                if (!studentIdInput.getInput().empty()) {
                    std::string ID = studentIdInput.getInput();
                    if (ID.size() != 9) {
                        popup("Student not found");
                        continue;
                    }
                    if (!course.removeStudent(ID))
                        popup("Student not found");
                    else {
                        popup("Student removed from course");
                        return;
                    }
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        studentIdInput.draw(windowNext);
        submitBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::exportStudentList(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Export student list", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/chooseFolder.png"))
        std::cout << "Could not load the File Browse image" << std::endl;
    std::cout << "Generate The Export List File sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField pathInput(151, 98, 695, 39, fontNext);
    Button browseBtn(151, 148, 150, 39, "Browse", fontNext, RED);
    InputField fileNameInput(151, 196, 406, 39, fontNext);
    Button submitBtn(151, 248, 150, 39, "Submit", fontNext, RED);

    pathInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (pathInput.isSelected()) pathInput.textCursor(pathInput.getInput());
        if (fileNameInput.isSelected()) fileNameInput.textCursor(fileNameInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                pathInput.handleMouseClick(mousePos);
                fileNameInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!pathInput.getInput().empty() && !fileNameInput.getInput().empty()) {
                        std::string path;
                        path = pathInput.getInput() + "/" + fileNameInput.getInput();
                        if (fsys::exists(path)) {
                            if (!confirm("File already exists.\nReplace the file?")) {
                                break;
                            }
                        }
                        fsys::path fPath(path);
                        if (course.exportStudentList(fPath))
                            popup("Student list exported");
                        else popup("Error processing export student list file");
                        return;
                    }
                }
                if (browseBtn.isClicked(mousePos)) {
                    std::string path(tinyfd_selectFolderDialog(0, 0));
                    std::cout << path << std::endl;
                    pathInput.input = path;
                    continue;
                }
            }
            pathInput.processInput(event);
            fileNameInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        pathInput.draw(windowNext);
        browseBtn.draw(windowNext);
        fileNameInput.draw(windowNext);
        submitBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::exportScoreBoard(Course& course) {
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Export scoreboard", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/chooseFolder.png"))
        std::cout << "Could not load the File Browse image" << std::endl;
    std::cout << "Generate The Export Scoreboard File sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField pathInput(151, 98, 695, 39, fontNext);
    Button browseBtn(151, 148, 150, 39, "Browse", fontNext, RED);
    InputField fileNameInput(151, 196, 406, 39, fontNext);
    Button submitBtn(151, 248, 150, 39, "Submit", fontNext, RED);

    pathInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (pathInput.isSelected()) pathInput.textCursor(pathInput.getInput());
        if (fileNameInput.isSelected()) fileNameInput.textCursor(fileNameInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                pathInput.handleMouseClick(mousePos);
                fileNameInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!pathInput.getInput().empty() && !fileNameInput.getInput().empty()) {
                        std::string path;
                        path = pathInput.getInput() + "/" + fileNameInput.getInput();
                        if (fsys::exists(path)) {
                            if (!confirm("File already exists.\nReplace the file?")) {
                                break;
                            }
                        }
                        fsys::path fPath(path);
                        if (course.exportScoreBoard(fPath))
                            popup("Scoreboard exported");
                        else popup("Error processing export scoreboard");
                        return;
                    }
                }
                if (browseBtn.isClicked(mousePos)) {
                    std::string path(tinyfd_selectFolderDialog(0, 0));
                    std::cout << path << std::endl;
                    pathInput.input = path;
                    continue;
                }
            }
            pathInput.processInput(event);
            fileNameInput.processInput(event);
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        pathInput.draw(windowNext);
        browseBtn.draw(windowNext);
        fileNameInput.draw(windowNext);
        submitBtn.draw(windowNext);

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
    Button exportListBtn(1420, 260, 240, 50, "Export list ", fontNext, RED);
    Button scoreBoardBtn(1420, 330, 240, 50, "ScoreBoard ", fontNext, RED);
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
        
        Text text(82.f, 188.f + (32*(i % 15)), temp, fontNext, BLACK, 32);

        listOfStudent.push_back(text);
    }


    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Button nextPageBtn(1526.f, 736.f, 92.f, 62.f, "Next", fontNext, sf::Color(218, 110, 50));
    Button prevPageBtn(1526.f, 813.f, 92.f, 62.f, "Prev", fontNext, sf::Color(218, 110, 50));
    vector<Text> allOfStudents;
    int displayFrom = 0;


    while (windowNext.isOpen()) {
        sf::Event event;
        long long displayLimit = (displayFrom + 15) > listOfStudent.size() ? listOfStudent.size() : (displayFrom + 15);
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (removeStudentBtn.isClicked(mousePos))
                {
                    long long before = oneclass.students.size();
                    removeStudent(oneclass);
                    long long after = oneclass.students.size();
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
                    return;
                }

                if (addStudentBtn.isClicked(mousePos))
                {
                    long long before = oneclass.students.size(); 
                    addStudent(oneclass);

                    long long after = oneclass.students.size(); 
                    if (before != after)
                    {
                        __int64 i = after - 1;
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
                    return;
                }

                if (exportListBtn.isClicked(mousePos)) {

                    popup("Export the list of student succes");
                }

                if (scoreBoardBtn.isClicked(mousePos)) {
                    scoreBoardOfClassStaff(oneclass);
                }

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + 15 <= listOfStudent.size())
                        displayFrom += 15;
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - 15 >= 0)
                        displayFrom -= 15;
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
        exportListBtn.draw(windowNext);
        scoreBoardBtn.draw(windowNext);

        for (int i = displayFrom; i < displayLimit; i++)
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
    
    Button getFromFile(850, 122, 245, 50, "Browse", fontNext, ORANGE);
    Button csvBtn(1200, 122, 245, 50, "Submit", fontNext, ORANGE);
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
                if (getFromFile.isClicked(mousePos))
                {
                    char* path = tinyfd_openFileDialog(0,0,0,0,0,0);
                    std::cout << std::string(path); 

                    csvInput.input = std::string(path); 
                }
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
                    
                    if (temp_basic_info.size() != 5)
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
                    if (path.substr(path.find_last_of('.')) != ".csv")
                        popup("Wrong file format.");
                    else
                    {
                        //check carefully here. 
                        bool valid_include = oneclass.getStudent(path);
                        
                        if (valid_include)
                        {
                            for (int i = 0; i < oneclass.students.size(); ++i)
                            {
                                if (!fsys::exists(oneclass.students[i].studentPath))
                                    oneclass.students[i].create();

                            }
                            
                            windowNext.close(); 
                        }
                        else popup("Wrong format of the file"); 
                    }
                    
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
        getFromFile.draw(windowNext); 
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

void Activity2::importScoreCourseStaff(Semester& semester, Course& course)
{
    sf::RenderWindow windowNext(sf::VideoMode(865, 392), "Import course's scoreboard", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/importFile.png"))
        std::cout << "Could not load the Course information image" << std::endl;
    std::cout << "Generate The Import List File sucess" << std::endl;
    sf::Sprite background(textureNext);

    InputField pathInput(151, 98, 695, 39, fontNext);
    Button browseBtn(151, 164, 150, 39, "Browse", fontNext, RED);
    Button submitBtn(331, 164, 150, 39, "Submit", fontNext, RED);

    pathInput.setSelected(true);

    while (windowNext.isOpen()) {
        sf::Event event;
        if (pathInput.isSelected()) pathInput.textCursor(pathInput.getInput());
        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                pathInput.handleMouseClick(mousePos);
                if (submitBtn.isClicked(mousePos)) {
                    if (!pathInput.getInput().empty()) {
                        if (!fsys::exists(pathInput.getInput())) {
                            popup("File not found");
                            break;
                        }
                        if (course.importScoreBoard(pathInput.getInput()))
                            popup("Scoreboard imported");
                        else popup("Error processing import scoreboard file (may be due to wrong input file)");
                        return;
                    }
                }
                if (browseBtn.isClicked(mousePos)) {
                    std::string path(tinyfd_openFileDialog(0, 0, 0, 0, 0, 0));
                    if (course.importScoreBoard(path))
                        popup("Scoreboard imported");
                    else popup("Error processing import scoreboard file"); 
                    return;
                }
            }
            pathInput.processInput(event);
            if (pathInput.chooseNextField()) {
                if (!pathInput.getInput().empty()) {
                    if (!fsys::exists(pathInput.getInput())) {
                        popup("File not found");
                        break;
                    }
                    if (course.importStudentsFile(pathInput.getInput()))
                        popup("Student list imported");
                    else popup("Error processing import student list file");
                    return;
                }
            }
        }

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);

        pathInput.draw(windowNext);
        browseBtn.draw(windowNext);
        submitBtn.draw(windowNext);

        windowNext.display();
    }
}

void Activity2::viewScoreboardStudent(vector<Subject>& listOfUnfinCourse)
{
    // ViewScoreBoardStudent.png
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "View scoreboard", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/ViewScoreBoardStudent.png"))
        std::cout << "Could not load the View scoreboard image" << std::endl;
    std::cout << "Generate The View scoreboard sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button horizontalLine(54, 157, 1545, 0, "", fontNext, BLACK);
    Button verticalLine1(99, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine2(280, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine3(745, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine4(870, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine5(1075, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine6(1228, 125, 0, 520, "", fontNext, BLACK);
    Button verticalLine7(1369, 125, 0, 520, "", fontNext, BLACK);
    

    Text noTxt(61, 125, "No", fontNext, GREEN, 26);
    Text courseIdTxt(112, 125, "Course's ID", fontNext, GREEN, 26);
    Text courseNameTxt(289, 125, "Course's Name", fontNext, GREEN, 26);
    Text finalTxt(754, 125, "Practice", fontNext, GREEN, 26);
    Text extraTxt(878, 125, "Midterm", fontNext, GREEN, 26);
    Text overallTxt(1083, 125, "Final", fontNext, GREEN, 26);
    Text exTxt(1237, 125, "Plus", fontNext, GREEN, 26);
    Text ex1Txt(1381, 125, "Overall", fontNext, GREEN, 26);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);


    vector<Text> scoreboard;
    for (int i = 0; i < listOfUnfinCourse.size(); i++) {
        std::string noStr = (i < 10) ? ('0' + std::to_string(i)) : (std::to_string(i));
        Text numTxt(54, (float)160 + 36 * ((i) % 10), noStr, fontNext, BLACK, 26);

        Text sIdTxt(115, (float)(160 + 36 * ((i) % 10)), listOfUnfinCourse[i].courseId, fontNext, BLACK, 26);
        Text sCTxt(300, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].courseName, fontNext, BLACK, 26);
        Text pracTxt(788, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].practiceScore, fontNext, BLACK, 26);
        Text midTxt(945, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].midScore, fontNext, BLACK, 26);
        Text finTxt(1131, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].finalScore, fontNext, BLACK, 26);
        Text plusTxt(1280, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].plusScore, fontNext, BLACK, 26);
        Text overTxt(1407, (float)160 + 36 * ((i) % 10), listOfUnfinCourse[i].aveScore, fontNext, RED, 26);

        scoreboard.push_back(numTxt);
        scoreboard.push_back(sIdTxt);
        scoreboard.push_back(sCTxt);
        scoreboard.push_back(pracTxt);
        scoreboard.push_back(midTxt);
        scoreboard.push_back(finTxt);
        scoreboard.push_back(plusTxt);
        scoreboard.push_back(overTxt);

    }

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

        horizontalLine.draw(windowNext);
        verticalLine1.draw(windowNext);
        verticalLine2.draw(windowNext);
        verticalLine3.draw(windowNext);
        verticalLine4.draw(windowNext);
        verticalLine5.draw(windowNext);
        verticalLine6.draw(windowNext);
        verticalLine7.draw(windowNext);

        noTxt.draw(windowNext);
        courseIdTxt.draw(windowNext);
        courseNameTxt.draw(windowNext);
        finalTxt.draw(windowNext);
        extraTxt.draw(windowNext);
        overallTxt.draw(windowNext);
        exTxt.draw(windowNext);
        ex1Txt.draw(windowNext);

        for (int i = 0; i < scoreboard  .size(); i++)
            scoreboard[i].draw(windowNext);

        goBackBtn.draw(windowNext);
        windowNext.display();
    }
}

// updateStudentScore.png
void Activity2::changeStudentScore(vector<std::string>& studentInfor)
{
    sf::RenderWindow windowNext(sf::VideoMode(1700, 950), "Update student's R�ult", sf::Style::Close | sf::Style::Titlebar);

    sf::Font fontNext;
    if (!fontNext.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Texture textureNext;
    if (!textureNext.loadFromFile("Assets/updateStudentScore.png"))
        std::cout << "Could not load the Update student result image" << std::endl;
    std::cout << "Generate update student result sucess" << std::endl;
    sf::Sprite background(textureNext);

    Button goBackBtn(686, 766, 245, 66, "Go back", fontNext, ORANGE);
    Button acceptBtn(970, 766, 245, 66, "Accept", fontNext, ORANGE);
    Text sId(162, 165, "Id: ", fontNext, BLACK, 32);
    Text sName(162, 251, "Name ", fontNext, BLACK, 32);
    Text sClass(162, 334, "Class ", fontNext, BLACK, 32);
    Text sPractice(909, 161, "Practice: ", fontNext, BLACK, 32);
    Text sMid(909, 248, "Midterm: ", fontNext, BLACK, 32);
    Text sPlus(909, 334, "Plus: ", fontNext, BLACK, 32);
    Text sFinal(909, 423, "Final: ", fontNext, BLACK, 32);
    Text sOveral(909, 506, "Overall: ", fontNext, BLACK, 32);

    InputField sIdInput(364, 162, 381, 50, fontNext); 
    InputField sNameInput(364, 251, 381, 50, fontNext);
    InputField sClassInput(364, 334, 381, 50, fontNext);
    InputField sPracticeInput(1111, 162, 381, 50, fontNext);
    InputField sMidInput(1111, 248, 381, 50, fontNext);
    InputField sPlusInput(1111, 334, 381, 50, fontNext);
    InputField sFinalInput(1111, 420, 381, 50, fontNext);
    InputField sOveralInput(1111, 506, 381, 50, fontNext);
    
    //Stu ID,       Class,      Name,       Practice Score, Midterm Score,      Final Score,    Plus Score, Other Score,    Average Score,
    sIdInput.input = studentInfor[0];
    sNameInput.input = studentInfor[2];
    sClassInput.input = studentInfor[1];
    sPracticeInput.input = studentInfor[3];
    sMidInput.input = studentInfor[4];
    sPlusInput.input = studentInfor[6];
    sFinalInput.input = studentInfor[5];
    sOveralInput.input = studentInfor[7];


    while (windowNext.isOpen()) {
        sf::Event event;
        if (sIdInput.isSelected()) sIdInput.textCursor(sIdInput.getInput());
        if (sNameInput.isSelected()) sNameInput.textCursor(sNameInput.getInput());
        if (sClassInput.isSelected()) sClassInput.textCursor(sClassInput.getInput());
        if (sPracticeInput.isSelected()) sPracticeInput.textCursor(sPracticeInput.getInput());
        if (sMidInput.isSelected()) sMidInput.textCursor(sMidInput.getInput());
        if (sPlusInput.isSelected()) sPlusInput.textCursor(sPlusInput.getInput());
        if (sFinalInput.isSelected()) sFinalInput.textCursor(sFinalInput.getInput());
        if (sOveralInput.isSelected()) sOveralInput.textCursor(sOveralInput.getInput());

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);
                sIdInput.handleMouseClick(mousePos);
                sNameInput.handleMouseClick(mousePos);
                sClassInput.handleMouseClick(mousePos);
                sPracticeInput.handleMouseClick(mousePos);
                sPlusInput.handleMouseClick(mousePos);
                sMidInput.handleMouseClick(mousePos);
                sFinalInput.handleMouseClick(mousePos);
                sOveralInput.handleMouseClick(mousePos);


                if (goBackBtn.isClicked(mousePos))
                    windowNext.close();

                if (acceptBtn.isClicked(mousePos)) {
                    // Solve the update student result
                }

            }
            sIdInput.processInput(event);
            sNameInput.processInput(event);
            sClassInput.processInput(event);
            sPracticeInput.processInput(event);
            sPlusInput.processInput(event);
            sMidInput.processInput(event);
            sFinalInput.processInput(event);
            sOveralInput.processInput(event);
        }

        

        windowNext.clear(sf::Color::White);
        windowNext.draw(background);
        goBackBtn.draw(windowNext);
        acceptBtn.draw(windowNext);

        sId.draw(windowNext);
        sName.draw(windowNext);
        sClass.draw(windowNext);
        sPractice.draw(windowNext);
        sMid.draw(windowNext);
        sPlus.draw(windowNext);
        sFinal.draw(windowNext);
        sOveral.draw(windowNext);

        sIdInput.draw(windowNext);
        sNameInput.draw(windowNext);
        sClassInput.draw(windowNext);
        sPracticeInput.draw(windowNext);
        sMidInput.draw(windowNext);
        sPlusInput.draw(windowNext);
        sFinalInput.draw(windowNext);
        sOveralInput.draw(windowNext);

        windowNext.display();
    }
}

bool Activity2::isSame(std::string& a, std::string& b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); ++i)
        if (tolower(a[i]) != tolower(b[i])) return false;
    return true;
}

