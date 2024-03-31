#pragma once
#include "Requirement.h"
namespace fsys = std::filesystem;
class Student 
{
private:
	fsys::path studentPath = "data/student";

	//more information about student
public: 
	Student(std::string ID);

	void getInfo();

	void getScoreBoard();

	Stack <std::string> getUnfinishedCourse();

};

