#include "Requirement.h"
int main()
{
    Drawio drawio;
    sf::RenderWindow window(sf::VideoMode(1700, 950), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar);

    std::cout << "Generate the main window success" << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        sf::RectangleShape header = drawio.Rectangle(100.0f, 100.0f, 50, 50, sf::Color::Red);

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

        
        window.draw(header);
        window.display();
        window.clear();
    }

    return 0;
}