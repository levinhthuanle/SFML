//#pragma once
//#include "Requirement.h"
//
//class SchoolYear {
//private:
//	std::string year;
//	Stack<Semester> semesters;
//	Stack<Class> classes;
//public:
//	SchoolYear(std::string year) : year(year) {
//
//		std::string directory = "data/" + year;
//
//		// for (const auto& entry : std::filesystem::directory_iterator(directory)) {
//		//     semesters.push(Semester(entry.path()));
//		// }
//	}
//	~SchoolYear() {
//		while (!semesters.isEmpty()) {
//			semesters.pop();
//		}
//	}
//	//Semester
//	void addSemester(Semester semester) { semesters.push(semester); }
//
//	void removeSemester() { semesters.pop(); }
//
//
//
//	Semester* getLastedSemester() {
//		return semesters.top();
//	}
//
//
//	bool inputNewSemester() {
//		std::string semesterName;
//		std::cout << "Enter semester name: ";
//		std::cin >> semesterName;
//		Semester semester(semesterName);
//		semesters.push(semester);
//		return true;
//	}
//
//	//Class
//	void addClass(Class newClass) {
//		classes.push(newClass);
//	}
//
//	Class* getClass() {
//		return classes.top();
//	}
//
//	void removeClass() { classes.pop(); }
//	bool inputNewClass() {
//		std::string className;
//		std::cout << "Enter class name: ";
//		std::cin >> className;
//		Class newClass(className);
//		classes.push(newClass);
//		return true;
//	}
//};
#include "Requirement.h"