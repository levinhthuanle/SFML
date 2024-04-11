//
//class Semester {
//private:
//	std::string name;
//	Date startDate;
//	Date endDate;
//	Stack<Course> courses;
//public:
	//Semester(std::string directory) {

	//	name = directory.substr(directory.find_last_of("/") + 1);
	//	std::ifstream file(directory + "/start_end_time.txt");
	//	std::string line;
	//	std::getline(file, line);
	//	startDate = Date(line);
	//	std::getline(file, line);
	//	endDate = Date(line);

	//	//for (const auto& entry : std::filesystem::directory_iterator(directory + "/courses")) {
	//	//    courses.push(Course(entry.path()));
	//	//}
	//}
	//~Semester() {
	//	while (!courses.empty()) {
	//		courses.pop();
	//	}
	//}

	//std::string getName() {
	//	return name;
	//}

	//Date getStartDate() {
	//	return startDate;
	//}

	//Date getEndDate() {
	//	return endDate;
	//}

	//Stack<Course> getCourses() {
	//	return courses;
	//}

	//void addCourse(Course course) {
	//	courses.push(course);
	//}

	//void removeCourse(Course course) {
	//	Stack<Course> temp;
	//	while (!courses.empty()) {
	//		if (courses.top().getName() != course.getName()) {
	//			temp.push(courses.top());
	//		}
	//		courses.pop();
	//	}
	//	while (!temp.empty()) {
	//		courses.push(temp.top());
	//		temp.pop();
	//	}
	//}
	//void save() {
	//    std::ofstream file("semesters/" + name + "/start_end_time.txt");
	//    file << startDate.toString() << std::endl;
	//    file << endDate.toString() << std::endl;
	//    file.close();
	//    std::filesystem::create_directory("semesters/" + name + "/courses");
	//    while (!courses.empty()) {
	//        courses.top().save();
	//        courses.pop();
	//    }
	//}

//};
#pragma once
#include "Requirement.h"
#include "Course.h"
#include "vector.h"

class Semester {
private:
	fsys::path filePath;
	std::string no;
	std::tm startDate;
	std::tm endDate;
	vector<Course> courses;

	Semester(fsys::path filePath, std::string no, std::tm start, std::tm end) {
		this->filePath = filePath;
		this->no = no;
		this->startDate = start;
		this->endDate = end;
	}

	Semester() {}

	void addCourse(std::string courseName) {
		
	}
};