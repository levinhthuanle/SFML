#include "Activity.h"


// Global variables


User user;
Calendar calendar;


vector<SchoolYear> existedSchoolYear = getExistedSchoolYear(); 
vector<Course> existedCourse = getAllCourse(existedSchoolYear);
//vector<Class> allClass = Class::getAllClassName();

//Finished
void Activity::initLoginWindow(sf::RenderWindow &window)
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
                    type += checkLoginType(user);
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
                type += checkLoginType(user);
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
    Text name(1446, 10, "Hello, " + user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Text days(1390, 133, "Mo Tu We Th Fr Sa Su", font, sf::Color(26, 114, 98), 25);
    Text newCalendar(1384, 169, calendar.text.getString().toAnsiString(), font, sf::Color(26, 114, 98), 25);

    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button createNewSYBtn(89.f, 106.f, 393, 55.f, "Create School Year", font, sf::Color(218, 110, 50));
    Button viewAllCoursesBtn(1375.f, 436.f, 300, 55, "View all courses", font, sf::Color(144, 44, 44));
    

    vector<Button> schoolYearButton; 
    for (int i = 0; i < min(existedSchoolYear.size(), 3LL); ++i)
    {
        Button newButton(89.0f , 106.0F +(i + 1) * 200, 393.f, 54.f, existedSchoolYear[i].getYear(), font, sf::Color(144, 44, 44));
        schoolYearButton.push_back(newButton); 
    }
    
    //for (int i = 0; i < allClass.size(); i++) {
    //    std::cout << allClass[i].classID << std::endl;
    //}

    if (!texture.loadFromFile("Assets/HomePageStaff.png"))
        std::cout << "Could not load the HomePageStaff image" << std::endl;
    std::cout << "Generate staff sucess" << std::endl;
    sf::Sprite background(texture);

    
    while (window.isOpen())
    {
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
                if (createNewSYBtn.isClicked(mousePos))
                {
                  
                    Activity2::createNewSchoolYearStaff();
                    //create second window to handle the work to create school year.
                }
                for (int i = 0; i < min(existedSchoolYear.size(), 3LL); ++i)
                {
                    if (schoolYearButton[i].isClicked(mousePos))
                    {

                        // 

                    }
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

        
        for (int i = 0; i < existedSchoolYear.size(); ++i)
            schoolYearButton[i].draw(window); 
        
        
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
