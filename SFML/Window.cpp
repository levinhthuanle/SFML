#include "Window.h"

void Window::initLoginWindow()
{    
    // Generate the main window
    sf::RenderWindow window(sf::VideoMode(1700, 950), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar);
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
        window.display(); // Display the window
    }
}
