#include "BuiltClasses.h"

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

int checkLoginType(User& user) // return 0 if wrong acc/pass, return 1 if student, return 2 if teacher
{
	std::string username = user.getUsername();
	std::string password = user.getPassword();
	if (username.size() != 9) return 0;

	//creating path
	fsys::path cla(username.begin(), username.begin() + 6);
	std::string User(username.begin() + 6, username.begin() + 9);

	std::cout << cla << std::endl;
	//try to open path
	std::string stringUser = User + ".csv";
	std::string type(username.begin(), username.begin() + 2);

	if (type != "00")
	{
		if (!fsys::exists("data/student" / cla / stringUser))
		{
			return 0;
		}
		else
		{
			std::ifstream fin;
			fin.open("data/student" / cla / stringUser);

			if (!fin.is_open()) 
				return 0;
			std::string p; fin >> p;

			//check valid
			if (p != password) return 0;

			std::string id, fullName, className;
			getline(fin, id); // Eat the carrier
			getline(fin, className);
			getline(fin, id);
			getline(fin, fullName);
			getline(fin, user.dayOfBirth);

			while (!fin.eof()) {
				std::string temp;
				getline(fin, temp);
				Subject tempSubject(temp);
				std::cout << temp << std::endl;
				if (tempSubject.completed)
					user.listOfFinCourse.push_back(tempSubject);
				else
					user.listOfUnfinCourse.push_back(tempSubject);
			}

			std::cout << id << '\n' << fullName << '\n' << className << '\n';
			std::cout << "Numer of courses:" << user.listOfFinCourse.size() << " " << user.listOfUnfinCourse.size() << std::endl;

			// Need to be change to private and use setter
			user.id = id;
			user.fullname = fullName;
			user.className = className;
			user.type = "Student";
			fsys::path temp = "data/student" / cla / stringUser;
			user.url = temp;

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
			if (p != password) return 0;
			user.setType("Staff");

			getline(fin, user.fullname);
			getline(fin, user.fullname);
			fsys::path temp = "data/staff" / cla / stringUser;
			user.url = temp;

			return 11; // return the correct number of activity type.
		}
	}
}

bool changePassword(User& user, std::string oldPassword, std::string newPassword, std::string cfNewPassword)
{
	if (user.getPassword() != oldPassword) {
		std::cout << "The old password you enter is not correct" << std::endl;
		return false;
	}

	if (newPassword != cfNewPassword) {
		std::cout << "The new Password and confirm Password does not match!" << std::endl;
		return false;
	}

	user.setPassword(newPassword);

	vector<std::string> listOfCourse;
	// Read all the course in the student file
	if (user.getType() == "Student") {

		std::ifstream fin;
		fin.open(user.url);
		if (!fin.is_open())
			std::cout << "Can not open information file to change password" << std::endl;

		std::string temp;
		for (int i = 1; i <= 5; i++)
			getline(fin, temp); // Pass the usser information
		while (!fin.eof()) {
			getline(fin, temp);
			listOfCourse.push_back(temp);
		}
		fin.close();
	}

	std::ofstream fout;
	fout.open(user.url);
	if (!fout.is_open()) {
		std::cout << "Can not open the user information file!" << std::endl;
		return false;
	}

	fout << user.getPassword() << std::endl;
	if (user.getType() == "Student") {
		fout << user.className << std::endl;
		fout << user.id << std::endl;
		fout << user.fullname << std::endl;
		fout << user.dayOfBirth << std::endl;

		for (int i = 0; i < listOfCourse.size(); i++)
			fout << listOfCourse[i] << std::endl;
	}

	else {
		fout << user.fullname << std::endl;
	}

	fout.close();

	std::cout << "Succesful change the password" << std::endl;
	return true;
}

// return a string containing all year. 
vector<std::string> getYearFolder()
{
	vector < std::string> classYear;
	fsys::path course("data/courses");
	std::string yearName;

	for (auto const& dir_entry : std::filesystem::directory_iterator{ course })
	{
		yearName = dir_entry.path().generic_string();
		classYear.push_back(yearName);

	}
	return classYear;

}
