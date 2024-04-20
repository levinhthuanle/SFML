#include "Activity.h"
// Global variables


User user;
Calendar calendar;


vector<SchoolYear> existedSchoolYear = getExistedSchoolYear(); 

vector<Course> existedCourse = getAllCourse(existedSchoolYear);
vector<Class> allClass = getAllClassName();

//Finished
void Activity::initLoginWindow(sf::RenderWindow &window, static bool& invalidLogin)
{    
    for (int i = 0; i < existedCourse.size(); ++i)
        std::cout << existedCourse[i].getID() << "\n";
    if (!texture.loadFromFile("Assets/Login.png"))
        std::cout << "Could not load the Login image" << std::endl;

    sf::Sprite background(texture);
    InputField username(661.f, 405.f, 370.f, 40.f, font);
    username.setSelected(true);
    InputField password(661.f, 538.f, 370.f, 40.f, font);
    Button loginBtn(692.f, 671.f, 313.f, 60.f, "Login", font, sf::Color(218, 100, 50));
    std::cout << "Generate the main window success" << std::endl;

    sf::Texture invalid;
    if (!invalid.loadFromFile("Assets/Invalid Login.png"))
        std::cout << "Could not load the Invalid Login image" << std::endl;
    sf::Sprite invalidLoginNoti(invalid);
    invalidLoginNoti.setPosition(652.f, 604.4f);

    while (window.isOpen()) {
        sf::Event event;
        if (username.isSelected()) username.textCursor(username.getInput());
        if (password.isSelected()) password.textCursor(password.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                username.handleMouseClick(mousePos);
                password.handleMouseClick(mousePos);

                if (loginBtn.isClicked(mousePos)) {
                    //login and setup type

                    user.setUsername(username.getInput());
                    user.setPassword(password.getInput());
                    int check = checkLoginType(user);
                    if (!check) invalidLogin = true;
                    else type += check;
                    //if (type != 0) loginLogic(user, username, password, type);
                    return; 
                }
            }
            username.processInput(event);
            if (username.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                password.setSelected(true);
            }
            password.processInput(event);
            if (password.chooseNextField()) {
                user.setUsername(username.getInput());
                user.setPassword(password.getInput());
                int check = checkLoginType(user);
                if (!check) invalidLogin = true;
                else type += check;
                /*if (type != 0) loginLogic(user, username, password, type);*/
                return;
            }
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        username.setSelected(username.isSelected() && !loginBtn.isClicked(mousePos));
        password.setSelected(password.isSelected() && !loginBtn.isClicked(mousePos));

        window.clear(sf::Color::White);
        window.draw(background);
        username.draw(window);
        password.draw(window);
        loginBtn.draw(window);
        if (invalidLogin) window.draw(invalidLoginNoti);
        window.display();
    }
}

// Finished
void Activity::initHomePageStudentWindow(sf::RenderWindow &window)
{
    Text name(1446, 10, "Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 35, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button nextPageBtn(1187.f, 732.f, 92.f, 62.f, "Next", font, sf::Color(218, 110, 50));
    Button prevPageBtn(1187.f, 809.f, 92.f, 62.f, "Prev", font, sf::Color(218, 110, 50));
    Button scoreboardBtn(1366, 433, 277, 55, "View score board", font, RED);

    int unfinshedCourse = 0, finishedCourse = 0;
    vector<courseButton> unfinBtn, finBtn;
    int displayFin = 0;
    for (int i = 0; i < user.listOfUnfinCourse.size(); i++) {
        if (i <= 3) {
            courseButton newCourseBtn((float)(52 + 280 * (i - unfinshedCourse)), 175, user.listOfUnfinCourse[i], font);
            unfinBtn.push_back(newCourseBtn);
        }
        else {
            courseButton newCourseBtn((float)(52 + 280 * (i - unfinshedCourse - 4)), 386, user.listOfUnfinCourse[i], font);
            unfinBtn.push_back(newCourseBtn);
        }
    }

    for (int i = 0; i < user.listOfFinCourse.size(); i++) {
        //float x, float y, Subject course, sf::Font font, sf::RenderWindow& window){
        courseButton newCourseBtn((float)(52 + 280 * (i % 4)), 670, user.listOfFinCourse[i], font);
        finBtn.push_back(newCourseBtn);

    }


    if (!texture.loadFromFile("Assets/HomePageStudent.png"))
        std::cout << "Could not load the HomePageStudent image" << std::endl;

    std::cout << "Generate Student Home Page success" << std::endl;
    sf::Sprite background(texture);


    while (window.isOpen()) {
        sf::Event event;
        long long tempFin = (displayFin + 4) > finBtn.size() ? finBtn.size() : (displayFin + 4);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (userIcon.isClicked(mousePos)) {
                    std::cout << "User has clicked the information icon" << std::endl;
                    type = 2; // initInformationWindow
                    return;
                }

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFin + 4 <= finBtn.size())
                    displayFin += 4;
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFin - 4 >= 0)
                        displayFin -= 4;
                }
                
                for (int i = 0; i < unfinBtn.size(); i++) {
                    if (unfinBtn[i].isClicked(mousePos)) {
                        std::cout << "User has click the unfinished button " << unfinBtn[i].cnt.courseId << std::endl;
                        Activity2::courseInformationStudent(unfinBtn[i].cnt);
                    }
                }

                for (int i = displayFin; i < tempFin; i++) {
                    if (finBtn[i].isClicked(mousePos)) {
                        std::cout << "User has click the finished button " << finBtn[i].cnt.courseId << std::endl;
                        Activity2::courseInformationStudent(finBtn[i].cnt);
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(background);


        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        for (int i = 0; i < unfinBtn.size(); i++)
            unfinBtn[i].draw(window);

        scoreboardBtn.draw(window);
        for (int i = displayFin; i < tempFin; i++) {
            finBtn[i].draw(window);
        }
        window.display();
    }

}

// Not yet finished - Do not have data
void Activity::initInformationStudentWindow(sf::RenderWindow& window)
{

    Text name(1446, 10,"Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBack(458, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));
    Button changePassword(833, 794, 372, 66, "Change password", font, sf::Color(218, 110, 50));

    Text  fullName(672, 163, "Full name: " + user.fullname, font, sf::Color::Black, 36);
    Text  id(672, 213, "Id: " + user.id, font, sf::Color::Black, 36);
    Text  course(672, 258, "Course: " + user.courseName, font, sf::Color::Black, 36);
    Text  classes(672, 300, "Class: " + user.courseName, font, sf::Color::Black, 36);


    if (!texture.loadFromFile("Assets/InformationStudent.png"))
        std::cout << "Could not load the InformationStudent image" << std::endl;

    std::cout << "Generate Student Information sucess" << std::endl;
    sf::Sprite background(texture);

    std::cout << user.url << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (goBack.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 1; // go back to initHomePageStudentWindow
                    return;
                }

                if (changePassword.isClicked(mousePos)) {
                    std::cout << "User has clicked the change password button" << std::endl;
                    type = 3; // changePasswordStudent
                    return;
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        fullName.draw(window);
        id.draw(window);
        course.draw(window);
        classes.draw(window);
        goBack.draw(window);
        changePassword.draw(window);

        window.display();
    }
}

// Not yet finished - Do not have data
void Activity::changePasswordStudentWindow(sf::RenderWindow& window)
{
    Text name(1446, 10,"Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBackBtn(458, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));
    Button confirmBtn(835, 794, 316, 66, "Accept change", font, sf::Color(218, 110, 50));

    InputField oldPassword(703.f, 189.f, 415.f, 51.f, font);
    InputField newPassword(703.f, 273.f, 415.f, 51.f, font);
    InputField cfNewPassword(703.f, 357.f, 415.f, 51.f, font);
    

    if (!texture.loadFromFile("Assets/changePasswordStudent.png"))
        std::cout << "Could not load the changePasswordStudent image" << std::endl;


    std::cout << "Generate change password student sucess" << std::endl;
    sf::Sprite background(texture);

    while (window.isOpen()) {
        sf::Event event;
        //if (password.isSelected()) password.textCursor(password.getInput());
        if (oldPassword.isSelected()) oldPassword.textCursor(oldPassword.getInput());
        if (newPassword.isSelected()) newPassword.textCursor(newPassword.getInput());
        if (cfNewPassword.isSelected()) cfNewPassword.textCursor(cfNewPassword.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                oldPassword.handleMouseClick(mousePos);
                newPassword.handleMouseClick(mousePos);
                cfNewPassword.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 1; // go back to initHomePageStudentWindow
                    return;
                }

                if (confirmBtn.isClicked(mousePos)) {
                    std::cout << "User has clicked the confirm change password" << std::endl;
                    type = 1;
                    changePassword(user, oldPassword.getInput(), newPassword.getInput(), cfNewPassword.getInput());
                    return;
                }

            }

            oldPassword.processInput(event);
            if (oldPassword.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                newPassword.setSelected(true);
            }
            newPassword.processInput(event);
            if (newPassword.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                cfNewPassword.setSelected(true);
            }
            cfNewPassword.processInput(event);
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        goBackBtn.draw(window);
        confirmBtn.draw(window);
        oldPassword.draw(window);
        newPassword.draw(window);
        cfNewPassword.draw(window);

        window.display();
    }
}

// Not yet finished - Do not have data
void Activity::viewCourseStudentWindow(sf::RenderWindow& window)
{
    Text name(1505, 10, user.getUsername(), font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBack(687, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));

    if (!texture.loadFromFile("Assets/YourCourseStudent.png"))
        std::cout << "Could not load the YourCourseStudent image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(texture);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (userIcon.isClicked(mousePos)) {
                    std::cout << "User has clicked the information icon" << std::endl;
                    type = 2; // initInformationWindow
                    return;
                }

                if (goBack.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 1; // go back to initHomePageStudentWindow
                    return;
                }
            }

        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        goBack.draw(window);
        window.display();
    }
}

// Not yet finished
void Activity::viewScoreStudentWindow(sf::RenderWindow& window)
{
    Text name(1505, 10, user.getUsername(), font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBack(687, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));

    if (!texture.loadFromFile("Assets/ViewScoreStudent.png"))
        std::cout << "Could not load the ViewScoreStudent image" << std::endl;
    std::cout << "Generate Your course student sucess" << std::endl;
    sf::Sprite background(texture);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (userIcon.isClicked(mousePos)) {
                    std::cout << "User has clicked the information icon" << std::endl;
                    type = 2; // initInformationWindow
                    return;
                }

                if (goBack.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 1; // go back to initHomePageStudentWindow
                    return;
                }
            }

        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        goBack.draw(window);
        window.display();
    }
}

//Finishing this function before next week.
//Adding create schoolyear button, show existing class & create more button

void Activity::initHomePageStaffWindow(sf::RenderWindow& window)
{
    const sf::Color RED = sf::Color(144, 44, 44);
    const sf::Color ORANGE = sf::Color(218, 110, 50);
    Text name(1446, 10, "Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Text days(1390, 133, "Mo Tu We Th Fr Sa Su", font, sf::Color(26, 114, 98), 25);
    Text newCalendar(1384, 169, calendar.text.getString().toAnsiString(), font, sf::Color(26, 114, 98), 25);
    Button nextPageBtn(1226.f, 750.f, 92.f, 62.f, "Next", font, ORANGE);
    Button prevPageBtn(1226.f, 827.f, 92.f, 62.f, "Prev", font, ORANGE);

    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button createNewSYBtn(51.f, 106.f, 450.f, 55.f, "Create School Year", font, ORANGE);
    Button viewAllCoursesBtn(1375.f, 436.f, 300, 55, "View all courses", font, RED);
    Button viewAllClassBtn(1380.f, 700.f, 250, 40, "View all >>", font, RED);
    Button createSemesterBtn(1046.f, 260.f, 230.f, 55.f, "Add semester", font, RED);
    Button addClassBtn(1093, 187, 181, 50, "Add Class", font, RED);

    int displaySY = 0;
    
    vector<schoolyearButton> schoolyearBtn;
    for (int i = 0; i < existedSchoolYear.size(); ++i)
    {
        schoolyearButton tempBtn(53.f, 190.f + 170.f * (i % 4), existedSchoolYear[i], font);
        schoolyearBtn.push_back(tempBtn); 
    }
    
    //for (int i = 0; i < allClass.size(); i++) {
    //    std::cout << allClass[i].classID << std::endl;
    //    std::cout << allClass[i].students[0].getID() << allClass[i].students[0].getFullname();
    //}
    vector<Button> displayBtn;
    for (int i = 0; i < min(allClass.size(),4LL); i++) {
        Button temp(1380.f + 140 * (i / 2), 584.f + 60*(i % 2), 120, 40, allClass[i].classID, font, sf::Color(144, 44, 44));
        displayBtn.push_back(temp);
    }

    if (!texture.loadFromFile("Assets/HomePageStaff.png"))
        std::cout << "Could not load the HomePageStaff image" << std::endl;
    std::cout << "Generate staff sucess" << std::endl;
    sf::Sprite background(texture);

    while (window.isOpen())
    {
        long long tempSY = (displaySY + 4) > existedSchoolYear.size() ? existedSchoolYear.size() : (displaySY + 4);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();  // Close 
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (userIcon.isClicked(mousePos)) {
                    std::cout << "User has clicked the information icon" << std::endl;
                    type = 12; // initInformationWindow
                    return;
                }

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displaySY + 4 <= existedSchoolYear.size())
                        displaySY += 4;
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displaySY - 4 >= 0)
                        displaySY -= 4;
                }

                if (createNewSYBtn.isClicked(mousePos))
                {
                    // Implement a function to create a new Schoolyear folder
                    if (existedSchoolYear[0].semester.size() == 3)
                    {
                        SchoolYear nextYear = existedSchoolYear[0].getNextPossibleYear(); 
                        nextYear.createNewSchoolYear(); 
                        existedSchoolYear.insert(nextYear, 0); 
                        schoolyearBtn.clear(); 
                        for (int i = 0; i < existedSchoolYear.size(); ++i)
                        {
                            schoolyearButton tempBtn(53.f, 190.f + 170.f * (i % 4), existedSchoolYear[i], font);
                            schoolyearBtn.push_back(tempBtn);
                        }
                    }
                    else
                    {
                        //show the error. 
                        Activity2::popup("The latest year hasn't been finished yet");
                        std::cerr << "The latest year hasn't been finished yet."; 
                    }
                }

                if (addClassBtn.isClicked(mousePos)) {
                    std::string lastYear = existedSchoolYear[0].year.substr(0, 2); 
                    Class tempClass; 
                    Activity2::addClassStaff(lastYear, tempClass);
                    if (tempClass.classID != "")
                    {
                        tempClass.create(); 
                        allClass.insert(tempClass, 0);
                        displayBtn.clear(); 
                        for (int i = 0; i < min(allClass.size(), 4LL); i++) 
                        {
                            Button temp(1380.f + 140 * (i / 2), 584.f + 60 * (i % 2), 120, 40, allClass[i].classID, font, sf::Color(144, 44, 44));
                            displayBtn.push_back(temp);
                        }
                        
                    }
                }

                if (viewAllCoursesBtn.isClicked(mousePos)) {
                    //Activity2::viewAllCourseStaff(existedCourse);
                    Activity2::viewAllCourseStaff(existedSchoolYear);
                }

                if (viewAllClassBtn.isClicked(mousePos)) {
                    Activity2::viewAllClassStaff(allClass);
                }

                if (createSemesterBtn.isClicked(mousePos))
                    if (displaySY == 0) {
                        if (existedSchoolYear[0].semester.size() < 3)
                        {
                            std::string lastYear = existedSchoolYear[0].year;
                            Semester newSemester (lastYear, "Semester" + std::to_string(existedSchoolYear[0].semester.size() + 1));
                            Activity2::createSemesterStaff(newSemester); 
                            if (newSemester.getStartDate().is_valid())
                            {
                                newSemester.create(); 
                                existedSchoolYear[0].semester.push_back(newSemester); 
                                schoolyearBtn[0] = schoolyearButton(53.f, 190.f + 170.f * (0 % 4), existedSchoolYear[0], font);
                                
                            }
                            
       
                        }

                        else Activity2::popup("Full of semesters in a year.");
                }

                for (int i = displaySY; i < tempSY; ++i){
                    if (schoolyearBtn[i].sem1.isClick(mousePos)) {
                        Activity2::viewCourseInSemester(schoolyearBtn[i].sem1.semester);
                    }

                    if (schoolyearBtn[i].sem2.isClick(mousePos)) {
                        Activity2::viewCourseInSemester(schoolyearBtn[i].sem2.semester);
                    }

                    if (schoolyearBtn[i].sem3.isClick(mousePos)) {
                        Activity2::viewCourseInSemester(schoolyearBtn[i].sem3.semester);
                    }
                }

                for (int i = 0; i < displayBtn.size(); i++) {
                    if (displayBtn[i].isClicked(mousePos))
                        Activity2::viewOneClass(allClass[i]);
                }             
            }

        }
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(calendar.text);
        //std::cout << calendar.text.getString().toAnsiString() << std::endl;

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        name.draw(window);
        createNewSYBtn.draw(window);
        viewAllCoursesBtn.draw(window);
        days.draw(window);
        newCalendar.draw(window);
        viewAllClassBtn.draw(window);
        addClassBtn.draw(window);
        for (int i = 0; i < displayBtn.size(); i++) {
            
            displayBtn[i].draw(window);
        }
        

        for (int i = displaySY; i < tempSY; i++) {
            schoolyearBtn[i].draw(window);
        }
        
        if (displaySY == 0 && (!schoolyearBtn[0].s1 || !schoolyearBtn[0].s2 || !schoolyearBtn[0].s3))
            createSemesterBtn.draw(window);

        window.display();

        
    }
        return;
}

void Activity::initInformationStaffWindow(sf::RenderWindow& window)
{
    //InformationStaff.png
    Text name(1446, 10,"Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBack(458, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));
    Button changePassword(833, 794, 372, 66, "Change password", font, sf::Color(218, 110, 50));

    Text  fullName(672, 163, "Full name: " + user.fullname, font, sf::Color::Black, 36);


    if (!texture.loadFromFile("Assets/InformationStaff.png"))
        std::cout << "Could not load the InformationStaff image" << std::endl;

    std::cout << "Generate Staff Information sucess" << std::endl;
    sf::Sprite background(texture);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (goBack.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 11; // go back to initHomePageStaffWindow
                    return;
                }

                if (changePassword.isClicked(mousePos)) {
                    std::cout << "User has clicked the change password button" << std::endl;
                    type = 13; // changePasswordStaff
                    return;
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        fullName.draw(window);
        goBack.draw(window);
        changePassword.draw(window);

        window.display();
    }
}

void Activity::changePasswordStaffWindow(sf::RenderWindow& window)
{
    Text name(1446, 10,"Hello, " +  user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBackBtn(458, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));
    Button confirmBtn(835, 794, 316, 66, "Accept change", font, sf::Color(218, 110, 50));

    InputField oldPassword(703.f, 189.f, 415.f, 51.f, font);
    InputField newPassword(703.f, 273.f, 415.f, 51.f, font);
    InputField cfNewPassword(703.f, 357.f, 415.f, 51.f, font);


    if (!texture.loadFromFile("Assets/changePasswordStaff.png"))
        std::cout << "Could not load the changePasswordStaff image" << std::endl;


    std::cout << "Generate change password student sucess" << std::endl;
    sf::Sprite background(texture);

    while (window.isOpen()) {
        sf::Event event;
        //if (password.isSelected()) password.textCursor(password.getInput());
        if (oldPassword.isSelected()) oldPassword.textCursor(oldPassword.getInput());
        if (newPassword.isSelected()) newPassword.textCursor(newPassword.getInput());
        if (cfNewPassword.isSelected()) cfNewPassword.textCursor(cfNewPassword.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                oldPassword.handleMouseClick(mousePos);
                newPassword.handleMouseClick(mousePos);
                cfNewPassword.handleMouseClick(mousePos);

                if (goBackBtn.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 11; // go back to initHomePageStaffWindow
                    return;
                }

                if (confirmBtn.isClicked(mousePos)) {
                    std::cout << "User has clicked the confirm change password" << std::endl;
                    type = 11;
                    changePassword(user, oldPassword.getInput(), newPassword.getInput(), cfNewPassword.getInput());
                    return;
                }

            }

            oldPassword.processInput(event);
            if (oldPassword.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                newPassword.setSelected(true);
            }
            newPassword.processInput(event);
            if (newPassword.chooseNextField()) {
                event.type = sf::Event::MouseButtonReleased;
                cfNewPassword.setSelected(true);
            }
            cfNewPassword.processInput(event);
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        goBackBtn.draw(window);
        confirmBtn.draw(window);
        oldPassword.draw(window);
        newPassword.draw(window);
        cfNewPassword.draw(window);

        window.display();
    }
}
