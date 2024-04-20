#pragma once
#include "Requirement.h"
#include "Components.h"
#include "User.h"
struct EF {
	static std::string getDateTime();
};

static void getSubjectData(User& user, fsys::path url)
{
	std::ifstream sub;

	sub.open(url);

	if (!sub.is_open()) {
		std::cout << "Can not open subject.csv file" << std::endl;
		return;
	}

	while (!sub.eof()) {
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

		std::cout << "temp: " << temp << std::endl;
		if (tempSubject.completed)
			user.listOfFinCourse.push_back(tempSubject);
		else
			user.listOfUnfinCourse.push_back(tempSubject);


	}
	sub.close();
}


int checkLoginType(User& user);

bool changePassword(User& user, std::string oldPassword, std::string newPassword, std:: string cfNewPassword);

template<class T>
const T& max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}
template<class T>
const T& min(const T& a, const T& b)
{
    return (a > b) ? b : a;
}


template<class T, class Compare>
const T& max(const T& a, const T& b, Compare comp)
{
    return (comp(a, b)) ? b : a;
}
template<class T, class Compare>
const T& min(const T& a, const T& b, Compare comp)
{
    return (comp(a, b)) ? a : b;
}



