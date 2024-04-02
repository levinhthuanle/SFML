#pragma once
#include "Requirement.h"
#include "Vector.h"
namespace fsys = std::filesystem;
class Student 
{
private:
	fsys::path studentPath = "data/student";

	//more information about student
public: 
	Student() {}

	Student(std::string ID);

	void getInfo();

	void getScoreBoard();

	vector<std::string> getUnfinishedCourse();

};

