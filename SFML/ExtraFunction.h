#pragma once
#include "Requirement.h"
#include <string>
struct EF {
	static std::string getDateTime();
};


int check_login_type(std::string acc, std::string pass) // return 0 if wrong acc/pass, return 1 if student, return 2 if teacher
{
	if (acc.size() != 8) return 0;
	//creating path
	fsys::path cla(acc.begin(), acc.begin() + 5);
	fsys::path stu(acc.begin() + 5, acc.begin() + 8);
	//try to open path

	if (!fsys::exists(cla / stu))
	{
		return 0;
	}
	else
	{
		//try to open file and check password.
		std::ifstream fin;
		fin.open(cla / stu / "password.txt");
		if (!fin.is_open()) return 0; 
		std::string p; fin >> p;
		if (p != pass) return 0;
		std::string type(p.begin(), p.begin() + 2);
		return 1 + (type == "00");
	}
}