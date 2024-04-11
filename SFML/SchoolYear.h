#pragma once
#include "Requirement.h"
#include "Semester.h"
#include "Class.h"
class SchoolYear {
private:
	std::string year;
	vector<Semester> semesters;
	vector<Class> classes;
public:
	SchoolYear() {}

	std::string getYear() {
		return year;
	}

	vector<Semester> getSemester() {
		return semesters;
	}

	vector<Class> getClasses() {
		return classes;
	}

	void setYear(std::string year) {
		this->year = year;
	}

	void setSemester(vector<Semester> semesters) {
		this->semesters = semesters;
	}

	void setClasses(vector<Class> classes) {
		this->classes = classes;
	}


};

