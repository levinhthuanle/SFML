#pragma once
#include "Requirement.h"

struct EF {
	static std::string getDateTime();
};


int checkLoginType(std::string username, std::string password);

#include "Components.h"
#include "User.h"
void loginLogic(User& user, InputField& username, InputField& password, int &type);