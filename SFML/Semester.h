#include "Requirement.h"
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