#include "Drawio.h"

sf::RectangleShape Drawio::Rectangle(float width, float height, int posX, int posY, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(posX, posY);
	return shape;
}
