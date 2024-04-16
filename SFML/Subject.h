#pragma once
#include "Requirement.h"

// Subject represent ONE course of the student
class Subject
{
public:
	std::string id;
	std::string name = "";
	int midScore = -1, finalScore = -1;
	int plusScore = -1, practiceScore = -1, aveScore = -1, otherScore = -1;
	std::string courseId = "", courseName = "", teacherName = "", days = "", time = "";
	int credits = 0, numOfStudents = 0, sessions = 0;
	bool completed = false;


	//CS162
	//	Introduction to Computer Science II
	//	Mr.Dinh Ba tien
	//	4
	//	50
	//	1
	//	Mon
	//	07:30
	//	- 1 - 1 - 1 - 1 - 1 - 1 - 1

	Subject() {}

	Subject(std::string id, std::string unsolved) {

		int isComplete;
		std::istringstream iss(unsolved);
		iss >> isComplete >> midScore >> practiceScore >> plusScore >> otherScore >> finalScore >> aveScore;

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

	void getScore() {

	}
};

