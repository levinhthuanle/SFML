#pragma once
#include "Requirement.h"
class Drawio
{
public:
	// Implement some function to draw stuff on the window
	static sf::RectangleShape Rectangle(float width, float height, float posX, float posY, sf::Color color);

	static sf::Sprite addImage(sf::RenderWindow &window , std::string url, float x, float y);
	
};

