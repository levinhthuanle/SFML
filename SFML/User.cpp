#include "User.h"

void User::setUrl(fsys::path url)
{
	this->url = url;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

void User::setPassword(std::string password) {
	this->password = password;
	std::fstream userFile;
	userFile.open(this->url, std::ios::trunc);
	userFile << password;
	userFile.close();
}

fsys::path User::getUrl()
{
	return url;
}

std::string User::getUsername()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

std::string User::getType()
{
	return type;
}

void User::updateSubjectData() {
	std::fstream sub(this->url / "subject.csv", std::ios::trunc);

	if (!sub.is_open()) {
		std::cout << "Can not open " << this->getUsername() << " subject.csv file" << std::endl;
		return;
	}

	for (Subject i : this->listOfFinCourse) {
		sub << i.courseId << '\n'
			<< i.courseName << '\n'
			<< i.credits << '\n'
			<< i.numOfStudents << '\n'
			<< i.sessions << '\n'
			<< i.days << '\n'
			<< i.time << '\n';
		if (i.completed) sub << "1 ";
		else sub << "-1 ";
		sub << i.midScore << " " << i.practiceScore << " " << i.plusScore << " " << i.otherScore << " " << i.finalScore << " " << i.aveScore << '\n';
	}

	for (Subject i : this->listOfUnfinCourse) {
		sub << i.courseId << '\n'
			<< i.courseName << '\n'
			<< i.credits << '\n'
			<< i.numOfStudents << '\n'
			<< i.sessions << '\n'
			<< i.days << '\n'
			<< i.time << '\n';
		if (i.completed) sub << "1 ";
		else sub << "-1 ";
		sub << i.midScore << " " << i.practiceScore << " " << i.plusScore << " " << i.otherScore << " " << i.finalScore << " " << i.aveScore;
	}

	sub.close();

}

