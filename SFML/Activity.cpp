#include "Activity.h"
// Global variables
User user;

// Not yet finished - Do not have the check valid function
void Activity::initLoginWindow(sf::RenderWindow &window)
{    

    if (!texture.loadFromFile("Assets/Login.png"))
        std::cout << "Could not load the Login image" << std::endl;

    sf::Sprite background(texture);
    InputField username(661.f, 405.f, 370.f, 40.f, font);
    InputField password(661.f, 538.f, 370.f, 40.f, font);
    Button loginBtn(692.f, 671.f, 313.f, 60.f, "Login", font, sf::Color(218, 100, 50));
    std::cout << "Generate the main window success" << std::endl;



    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                username.handleMouseClick(mousePos);
                password.handleMouseClick(mousePos);

                if (loginBtn.isClicked(mousePos)) {
                    //login and setup type
                    std::cout << "Username: " << username.getInput() << std::endl;
                    std::cout << "Password: " << password.getInput() << std::endl;
                    
                    user.setUsername(username.getInput());
                    user.setPassword(username.getInput());
                    user.setType("Student");

                    
                    std::cout << checkLoginType(user.getUsername(), user.getPassword()) << std::endl;
                    type = 1; // initHomePageStudentWindow
                    return; 
                }
            }
            username.processInput(event);
            password.processInput(event);
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
    

    Text name(1505, 10, user.getUsername(), font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Button yourCourse(130, 162, 521, 90, "Your course", font, sf::Color(218, 110, 50));
    Button viewScore(130, 307, 521, 93, "View your score", font, sf::Color(218, 110, 50));
    Circle userIcon(1403, 35, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));

    if (!texture.loadFromFile("Assets/HomePageStudent.png"))
        std::cout << "Could not load the HomePageStudent image" << std::endl;

    std::cout << "Generate Student Home Page success" << std::endl;
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
                
                if (yourCourse.isClicked(mousePos)) {
                    std::cout << "User has clicked the your course button" << std::endl;
                    type = 4; // viewCourseStudentWindow
                    return;
                }

            }
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        yourCourse.draw(window);
        viewScore.draw(window);
        userIcon.draw(window);

        window.display();
    }

}

// Not yet finished - Do not have data
void Activity::initInformationStudentWindow(sf::RenderWindow& window)
{

    Text name(1505, 10, user.getUsername(), font, sf::Color(255, 255, 255), 20);
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
    Text name(1505, 10, user.fullname, font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
    Circle userIcon(1403, 40, 28, "Assets/userIcon.png", sf::Color(255, 250, 250));
    Button goBack(458, 794, 245, 66, "Go back", font, sf::Color(218, 110, 50));

    InputField oldPassword(703.f, 189.f, 415.f, 51.f, font);
    InputField newPassword(703.f, 273.f, 415.f, 51.f, font);
    InputField cfNewPassword(703.f, 357.f, 415.f, 51.f, font);
    

    if (!texture.loadFromFile("Assets/changePasswordStudent.png"))
        std::cout << "Could not load the changePasswordStudent image" << std::endl;


    std::cout << "Generate change password student sucess" << std::endl;
    sf::Sprite background(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                oldPassword.handleMouseClick(mousePos);
                newPassword.handleMouseClick(mousePos);
                cfNewPassword.handleMouseClick(mousePos);

                if (goBack.isClicked(mousePos)) {
                    std::cout << "User has clicked the go back button" << std::endl;
                    type = 1; // go back to initHomePageStudentWindow
                    return;
                }


            }

            oldPassword.processInput(event);
            newPassword.processInput(event);
            cfNewPassword.processInput(event);
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        userIcon.draw(window);
        goBack.draw(window);
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

void Activity::viewScoreStudentWindow(sf::RenderWindow& window)
{
}
