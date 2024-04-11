#include "Drawio.h"

sf::RectangleShape Drawio::Rectangle(float width, float height, float posX, float posY, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(posX, posY);
	return shape;
}

sf::Sprite Drawio::addImage(sf::RenderWindow &window, std::string url, float x, float y)
{
    sf::Texture texture;

    if (!texture.loadFromFile(url)) {
        // Handle error if the image file cannot be loaded
        std::cout << "Can not load image";
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);

    window.draw(sprite);
    return sprite;
}
