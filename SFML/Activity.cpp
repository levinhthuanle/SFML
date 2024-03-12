#include "Activity.h"

void Activity::initLoginWindow()
{    
    // Generate the main window
    sf::RenderWindow window(sf::VideoMode(x, y), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar);
    std::cout << "Generate the main window success" << std::endl;

    // Main loop
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {
                    printf("%c", event.text.unicode);
                }
                break;

            default:
                break;
            }
        }
        
        window.clear(); // Clear the window first

        Drawio::addImage(window, "Login.png", 0, 0);

        window.display(); // Display the window
    }
}
