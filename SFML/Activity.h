#pragma once
#include "Requirement.h"

#include "Drawio.h"
#include "Components.h"

#include "LinkList.h"
#include "Vector.h"
#include "FileNFolder.h"
#include "ExtraFunction.h"


#include "Teacher.h"
#include "Student.h"
#include "SchoolYear.h"
#include "Semester.h"
#include "Date.h"
#include "Class.h"
#include "Course.h"
#include "User.h"

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

	// Staff

	void initHomePageStaffWindow(sf::RenderWindow& window);

	void initInformationStaffWindow(sf::RenderWindow& window);

	void changePasswordStaffWindow(sf::RenderWindow& window);
};