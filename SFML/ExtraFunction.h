#pragma once
#include "Requirement.h"
#include "Components.h"
#include "User.h"

struct EF {
	static std::string getDateTime();
};


int checkLoginType(std::string username, std::string password);


void loginLogic(User& user, InputField& username, InputField& password , int& type);