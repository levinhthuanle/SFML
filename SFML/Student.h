#pragma once
#include "Requirement.h"
class Student 
{
private:
	fsys::path studentPath = "data/student";
public: 
	Student(std::string ID)
	{
		std::string clas(ID.begin(), ID.begin() + 5 + (ID.size() == 9)); 
		std::string num(ID.begin() + 5 + (ID.size() == 9), ID.begin() + 8 + (ID.size() == 9)); 
		this->studentPath =  this -> studentPath / clas / num; 
	}
	void showInfo()
	{

	}
	void showScoreBoard()
	{

	}
	Stack <std::string> getUnfinishedCourse()
	{

	}

};

