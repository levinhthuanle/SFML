#pragma once
#include "Requirement.h"
namespace fsys = std::filesystem;
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
		return;
	}
	void showScoreBoard()
	{
		return; 
	}
	Stack <std::string> getUnfinishedCourse()
	{
		Stack <std::string> s; 
		return s; 
	}

};

