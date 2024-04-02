#include "Student.h"

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
	return vector<std::string>();
}