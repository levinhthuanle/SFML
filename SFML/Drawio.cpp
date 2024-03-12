#include "Drawio.h"

sf::RectangleShape Drawio::Rectangle(float width, float height, int posX, int posY, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(posX, posY);
	return shape;
}

void Drawio::addImage(sf::RenderWindow &window, std::string url, int x, int y)
{
    sf::Texture texture;

    if (!texture.loadFromFile("Login.png")) {
        // Handle error if the image file cannot be loaded
        std::cout << "Can not load image";
    }

    sf::Sprite sprite(texture);

    window.draw(sprite);
}
