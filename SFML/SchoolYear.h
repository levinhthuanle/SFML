#pragma once
#include "Requirement.h"
#include "Semester.h"
#include "Class.h"
class SchoolYear {
private:
	std::string year;
	Semester smtr1;
	Semester smtr2;
	Semester smtr3;
	vector<Class> classes;
public:
	SchoolYear() {}

	std::string getYear() {
		return year;
	}

	void setYear(std::string year) {
		this->year = year;
	}





};

