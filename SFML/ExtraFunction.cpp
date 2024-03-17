#include "ExtraFunction.h"

std::string EF::getDateTime()
{
    // Get current time
    std::time_t now = std::time(nullptr);

    // Convert to local time
    std::tm localTime;
    localtime_s(&localTime, &now);

    // Format the date
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << localTime.tm_mday << "/"
        << std::setw(2) << (localTime.tm_mon + 1) << "/" << (localTime.tm_year + 1900);

    return ss.str();
}

int checkLoginType(std::string acc, std::string pass) // return 0 if wrong acc/pass, return 1 if student, return 2 if teacher
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