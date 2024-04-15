#pragma once
#include "Subject.h"
#include "Components.h"
#include "vector.h"
//I assume that this class create sub-activity for student. 
const sf::Color black = sf::Color(18, 2, 2);
const sf::Color green = sf::Color(81, 161, 147);
const sf::Color orange = sf::Color(218, 110, 50);
class Activity2
{
public:


	Activity2() {

	}

	//courseInformationStudent(unfinBtn[i].cnt)
	static void courseInformationStudent(Subject subject);

	static void createNewSchoolYearStaff();

};

