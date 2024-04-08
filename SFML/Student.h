#pragma once
#include "Requirement.h"
#include "Vector.h"
#include "User.h"
namespace fsys = std::filesystem;
class Student 
{
private:


	fsys::path studentPath;
	User user;
	//more information about student
public: 
	Student() {}

	Student(std::string ID);

	Student(User user) {
		this->user = user;
		this->studentPath = user.getUrl();
	}

	void getInfo();

	

	vector<std::string> getUnfinishedCourse();
	
	vector<std::string> getFinishedCourse();

	void getScoreBoard();

	void changePassword(std::string newPass) {
		this->user.setPassword(newPass);
	}
};


