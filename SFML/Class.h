#pragma once
#include "Requirement.h"
#include "LinkList.h" 
#include "Student.h"
class Class {
private:
    std::string classID, className;
    Stack<Student> students;

public:
	Class(std::string classID, std::string className) {
		this->classID = classID;
		this->className = className;
	}

	Class(std::string className) {
		this->className = className;
	}

	//~Class() {
	//	while (!students.isEmpty()) {
	//		students.pop();
	//	}
	//}

	std::string getClassID();

	std::string getClassName();

	void setClassID(std::string classID);

	void setClassName(std::string className);

	//Student
	//void addStudent(Student student) {
	//	students.push(student);
	//}
	//Stack<Student> getStudents() {
	//	return students;
	//}
};