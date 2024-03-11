#pragma once
#include "Requirement.h"
class Drawio
{
public:
	// Implement some function to draw stuff on the window
	sf::RectangleShape Rectangle(float width, float height, int posX, int posY, sf::Color color);

	sf::Sprite addImage(std::string url, int x, int y);
};

