#pragma once
#include "Requirement.h"

class Activity {
public:
	int type = 0; 
	sf::Font font;
	sf::Texture texture;

	Activity() {
		if (!font.loadFromFile("TextFont/arial.ttf"))
			std::cout << "Could not load the font" << std::endl;
	}

	// Student
	void initLoginWindow(sf::RenderWindow &window);

	void initHomePageStudentWindow(sf::RenderWindow& window);

	void initInformationStudentWindow(sf::RenderWindow& window);

	void changePasswordStudentWindow(sf::RenderWindow& window);

	void viewCourseStudentWindow(sf::RenderWindow& window);

	void viewScoreStudentWindow(sf::RenderWindow& window);

	void initHomePageStaffWindow(sf::RenderWindow& window);
};
