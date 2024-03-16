#pragma once
#include "Requirement.h"

struct EF {
	static std::string getDateTime();
};


int check_login_type(std::string acc, std::string pass);