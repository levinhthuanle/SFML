#pragma once
#include "Requirement.h"
#include "Subject.h"

// Subject represent ONE course of the student
class Subject
{
public:
	std::string name = "";
	int midScore = -1;
	int finalScore = -1;
	int plusScore = -1;
	int practiceScore = -1;
	int aveScore = -1;
	int otherScore = -1;
	bool completed = false;

	Subject() {}

	Subject(std::string unsolved) {
		int isComplete;
		std::istringstream iss(unsolved);
		iss >> name >> midScore >> practiceScore >> plusScore >> otherScore >> finalScore >> aveScore >> isComplete;

		if (isComplete == 1)
			completed = true;
		else
			completed = false;
	}

	~Subject() {
		name = "";
		midScore = finalScore = plusScore = practiceScore = aveScore = otherScore == -1;
		completed = false;
	}
};

