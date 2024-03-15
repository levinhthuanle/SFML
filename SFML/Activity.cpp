#include "Activity.h"
// Global variables
User user;

void Activity::initLoginWindow(sf::RenderWindow &window)
{    
    // Generate the main window
    
    sf::Texture texture;
    sf::Font font;

    if (!texture.loadFromFile("Assets/Login.png"))
        std::cout << "Could not load the backrground image" << std::endl;
    if (!font.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

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
                    std::cout << "Username: " << username.getInput() << std::endl;
                    std::cout << "Password: " << password.getInput() << std::endl;
                    type++;
                    user.setUsername(username.getInput());
                    user.setPassword(username.getInput());
                    user.setType("Student");
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

void Activity::initHomePageStudentWindow(sf::RenderWindow &window)
{
    
    sf::Texture texture;
    sf::Font font;

    Text name(1505, 10, user.getUsername(), font, sf::Color(255, 255, 255), 20);
    Text datetime(1446, 40, EF::getDateTime(), font, sf::Color(255, 255, 255), 20);
   

    if (!texture.loadFromFile("Assets/HomePageStudent.png"))
        std::cout << "Could not load the backrground image" << std::endl;
    if (!font.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    std::cout << "Generate Student Home Page success" << std::endl;
    sf::Sprite background(texture);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();  // Close 
        }

        window.clear(sf::Color::White);
        window.draw(background);

        name.draw(window);
        datetime.draw(window);
        window.display();
    }

}

void Activity::initInformationWindow(sf::RenderWindow& window)
{
    //sf::RenderWindow window(sf::VideoMode(x, y), "Course management system", sf::Style::Close | sf::Style::Titlebar);

    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed)
    //            window.close();  // Close 
    //    }

    //    window.clear(sf::Color::White);
    //    window.display();
    //}
}
