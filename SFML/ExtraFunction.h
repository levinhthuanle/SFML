#pragma once
#include "Requirement.h"
#include "Components.h"
#include "User.h"
struct EF {
	static std::string getDateTime();
};


int checkLoginType(User& user);

bool changePassword(User& user, std::string oldPassword, std::string newPassword, std:: string cfNewPassword);