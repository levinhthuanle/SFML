#pragma once
#include "Requirement.h"
class Drawio
{
public:
	// Implement some function to draw stuff on the window
	static sf::RectangleShape Rectangle(float width, float height, int posX, int posY, sf::Color color);

	static void addImage(sf::RenderWindow &window , std::string url, int x, int y);
	
};

