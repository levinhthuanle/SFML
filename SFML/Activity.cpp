#include "Activity.h"

void Activity::initLoginWindow()
{    
    // Generate the main window
    sf::RenderWindow window(sf::VideoMode(x, y), "Course management system", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture texture;
    sf::Font font;

    if (!texture.loadFromFile("Assets/Login.png"))
        std::cout << "Could not load the backrground image" << std::endl;
    if (!font.loadFromFile("TextFont/arial.ttf"))
        std::cout << "Could not load the font" << std::endl;

    sf::Sprite background(texture);
    InputField username(661.f, 405.f, 370.f, 40.f, font);
    InputField password(661.f, 538.f, 370.f, 40.f, font);
    Button loginButton(692.f, 671.f, 313.f, 60.f, "Login", font, sf::Color(218, 100, 50));
    std::cout << "Generate the main window success" << std::endl;



    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                username.handleMouseClick(mousePos);
                password.handleMouseClick(mousePos);
                if (loginButton.isClicked(mousePos)) {
                    std::cout << "Username: " << username.getInput() << std::endl;
                    std::cout << "Password: " << password.getInput() << std::endl;
                }
            }
            username.processInput(event);
            password.processInput(event);
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        username.setSelected(username.isSelected() && !loginButton.isClicked(mousePos));
        password.setSelected(password.isSelected() && !loginButton.isClicked(mousePos));

        window.clear(sf::Color::White);
        window.draw(background);
        username.draw(window);
        password.draw(window);
        loginButton.draw(window);
        window.display();
    }
}