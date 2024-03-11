#include "Drawio.h"

sf::RectangleShape Drawio::Rectangle(float width, float height, int posX, int posY, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(posX, posY);
	return shape;
}

sf::Sprite Drawio::addImage(std::string url, int x, int y)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(url)) {
        // Handle error if the image file cannot be loaded
        std::cout << "Can not load image";
        return sprite;
    }

    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    return sprite;
}
