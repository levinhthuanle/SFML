#pragma once
#include "Requirement.h"

struct EF {
	static std::string getDateTime();
};


int checkLoginType(std::string username, std::string password);