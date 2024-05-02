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
	std::fstream sub(this->url / "subject.csv", std::ios::out);

	if (!sub.is_open()) {
		std::cout << "Can not open " << this->getUsername() << " subject.csv file" << std::endl;
		return;
	}

	for (int i = 0; i < this->listOfUnfinCourse.size(); ++i) {
		sub << this->listOfUnfinCourse[i].courseId << '\n'
			<< this->listOfUnfinCourse[i].courseName << '\n'
			<< this->listOfUnfinCourse[i].teacherName << '\n'
			<< this->listOfUnfinCourse[i].credits << '\n'
			<< this->listOfUnfinCourse[i].numOfStudents << '\n'
			<< this->listOfUnfinCourse[i].sessions << '\n'
			<< this->listOfUnfinCourse[i].days << '\n'
			<< this->listOfUnfinCourse[i].time << '\n';
		if (this->listOfUnfinCourse[i].completed) sub << "1 ";
		else sub << "-1 ";
		sub << this->listOfUnfinCourse[i].midScore << " " << this->listOfUnfinCourse[i].practiceScore << " " << this->listOfUnfinCourse[i].plusScore << " " << 
			this->listOfUnfinCourse[i].otherScore << " " << this->listOfUnfinCourse[i].finalScore << " " << this->listOfUnfinCourse[i].aveScore << '\n';
	}

	for (int i = 0; i < this->listOfFinCourse.size(); ++i) {
		sub << this->listOfFinCourse[i].courseId << '\n'
			<< this->listOfFinCourse[i].courseName << '\n'
			<< this->listOfFinCourse[i].teacherName << '\n'
			<< this->listOfFinCourse[i].credits << '\n'
			<< this->listOfFinCourse[i].numOfStudents << '\n'
			<< this->listOfFinCourse[i].sessions << '\n'
			<< this->listOfFinCourse[i].days << '\n'
			<< this->listOfFinCourse[i].time << '\n';
		if (this->listOfFinCourse[i].completed) sub << "1 ";
		else sub << "-1 ";
		sub << this->listOfFinCourse[i].midScore << " " << this->listOfFinCourse[i].practiceScore << " " << this->listOfFinCourse[i].plusScore << " " << 
			this->listOfFinCourse[i].otherScore << " " << this->listOfFinCourse[i].finalScore << " " << this->listOfFinCourse[i].aveScore;
	}

	sub.close();

}

