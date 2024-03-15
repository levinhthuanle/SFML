#pragma once
#include "Requirement.h"

class Activity {
public:
	int type = 0; 
	void initLoginWindow(sf::RenderWindow &window);

	void initHomePageStudentWindow(sf::RenderWindow& window);

	void initInformationWindow(sf::RenderWindow& window);
};