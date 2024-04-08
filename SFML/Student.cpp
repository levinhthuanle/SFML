#include "Student.h"
#include "Requirement.h"
Student::Student(std::string ID){
	std::string clas(ID.begin(), ID.begin() + 5 + (ID.size() == 9));
	std::string num(ID.begin() + 5 + (ID.size() == 9), ID.begin() + 8 + (ID.size() == 9));
	this->studentPath = this->studentPath / clas / num;
}

void Student::getInfo()
{
		return;
}

void Student::getScoreBoard()
{
	return;
}

vector<std::string> Student::getUnfinishedCourse()
{
	std::ifstream fin(studentPath); 
	std::string unnecessary; 
	for (int i = 0; i < 4; ++i)
	{
		std::getline(fin, unnecessary);
	}
	std::string classCode; 
	vector <std::string> course; 
	while (std::getline(fin, classCode))
	{
		if (classCode == "\n") break;
		else course.push_back(classCode); 
	}
	return course;
}

vector<std::string> Student::getFinishedCourse()
{
	{
		std::ifstream fin(studentPath);
		std::string classCode; 
		vector<std::string> course; 
		while (std::getline(fin, classCode))
		{
			if (classCode == "\n") break;
			else course.push_back(classCode);
		}
		while (std::getline(fin, classCode))
		{
			if (classCode == "\n") break;
			else course.push_back(classCode);
		}
		return course;
	}
}