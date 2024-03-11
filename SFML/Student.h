#pragma once
#include "Requirement.h"

class Student
{
private:
	std::string username;
	std::string password;
public:
	Student() {
		username = password = "";
	}
	Student(std::string username, std::string password) {
		this->username = username;
		this->password = password;
	}

	void setUsername(std::string username);

	std::string getUsername();

};

