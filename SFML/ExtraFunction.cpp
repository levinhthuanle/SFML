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
	if (acc.size() != 9) return 0;
	//creating path
	fsys::path cla(acc.begin(), acc.begin() + 6);
	std::string user(acc.begin() + 6, acc.begin() + 9);
	//try to open path
	std::string stringUser = user + ".csv";
	std::string type(acc.begin(), acc.begin() + 2);

	if (type != "00")
	{
		if (!fsys::exists("data/student" / cla / stringUser))
		{
			return 0;
		}
		else
		{

			//try to open file and get password.

			std::ifstream fin;
			fin.open("data/student" / cla / stringUser);

			if (!fin.is_open()) return 0;
			std::string p; fin >> p;

			//check valid
			if (p != pass) return 0;



			return 1;
		}
	}
	else
	{
		if (!fsys::exists("data/staff" / cla / stringUser))
		{
			return 0;
		}
		else
		{

			//try to open file and get password.

			std::ifstream fin;
			fin.open("data/staff" / cla / stringUser);

			if (!fin.is_open()) return 0;
			std::string p; fin >> p;

			//check valid
			if (p != pass) return 0;



			return 11; // return the correct number of activity type.
		}
	}
}

void loginLogic(User& user, InputField& username, InputField& password, int& type) {
	std::cout << "Username: " << username.getInput() << std::endl;
	std::cout << "Password: " << password.getInput() << std::endl;

	user.setUsername(username.getInput());
	user.setPassword(username.getInput());

	if (type == 1) user.setType("Student");
	else if (type == 2) user.setType("Staff");;

	std::cout << checkLoginType(user.getUsername(), user.getPassword()) << std::endl;
}