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



void getSubjectData(User& user, fsys::path url)
{
	std::ifstream sub;
	
	sub.open(url); 

	if (!sub.is_open()) {
		std::cout << "Can not open subject.csv file" << std::endl;
		return;
	}

	while(!sub.eof()){
		std::string courseId, courseName, teacherName, days, time, temp;
		int credits, numOfStudents, sessions;

		getline(sub, courseId);
		getline(sub, courseName);
		getline(sub, teacherName);
		sub >> credits; getline(sub, temp);
		sub >> numOfStudents; getline(sub, temp);
		sub >> sessions; getline(sub, temp);
		getline(sub, days);
		getline(sub, time);
	

		getline(sub, temp);
		Subject tempSubject("", temp);

		tempSubject.courseId = courseId;
		tempSubject.courseName = courseName;
		tempSubject.teacherName = teacherName;
		tempSubject.days = days;
		tempSubject.time = time;
		tempSubject.credits = credits;
		tempSubject.numOfStudents = numOfStudents;
		tempSubject.sessions = sessions;

		std::cout << "temp: " <<  temp << std::endl;
		if (tempSubject.completed)
			user.listOfFinCourse.push_back(tempSubject);
		else
			user.listOfUnfinCourse.push_back(tempSubject);

		
	}
	sub.close();
}

int checkLoginType(User& user) // return 0 if wrong acc/pass, return 1 if student, return 2 if teacher
{
	std::string username = user.getUsername();
	std::string password = user.getPassword();
	if (username.size() != 9) return 0;

	//creating path
	fsys::path cla(username.begin(), username.begin() + 6);
	std::string User(username.begin() + 6, username.begin() + 9);

	std::cout << "cla: " << cla << std::endl;
	//try to open path
	std::string stringUser = User + "/" + User + ".txt";
	std::string type(username.begin(), username.begin() + 2);

	std::cout << "User: " << User << std::endl;

	if (type != "00")
	{
		fsys::path finPath("data/student" / cla / User / "password.txt");
		std::cout << finPath << std::endl;
		if (!fsys::exists(finPath))
		{
			return 0;
		}
		else
		{
			std::ifstream fin;
			fin.open("data/student" / cla / User / "password.txt");

			if (!fin.is_open()) 
				return 0;
			std::string p; fin >> p;
			std::cout << "pass: " << p << std::endl;
			fin.close(); 
			//check valid
			if (p != password) return 0;

			std::string subjectUrl = User + "/" + User + "_subject.csv";
			getSubjectData(user, "data/student" / cla / subjectUrl);

			fin.open("data/student" / cla / stringUser);

			getline(fin, user.id);
			getline(fin, user.className);
			getline(fin, user.fullname);
			getline(fin, user.gender);
			getline(fin, user.socialId);
			std::cout << user.id << '\n' << user.fullname << '\n' << user.className << '\n';

			std::cout << "Numer of courses:" << user.listOfFinCourse.size() << " " << user.listOfUnfinCourse.size() << std::endl;

			// Need to be change to private and use setter
			user.type = "Student";
			fsys::path temp = "data/student" / cla / stringUser;
			user.url = temp;
			fin.close();
			return 1;
		}
	}
	else
	{
		User += ".csv";
		fsys::path finPath("data/staff" / cla / User);
		std::cout << finPath << std::endl;

		if (!fsys::exists(finPath))
		{
			return 0;
		}

		else
		{
			//try to open file and get password.

			std::ifstream fin;
			fin.open(finPath);

			if (!fin.is_open()) return 0;
			std::string p; std::getline(fin, p, ',');
			std::cout << "pass: " << p << std::endl;
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
