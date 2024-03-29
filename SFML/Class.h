#pragma once
#include "Requirement.h"

class Class {
private:
    std::string classID, className;
    Stack<Student> students;
public:
    Class(std::string classID, std::string className) {
		this->classID = classID;
		this->className = className;
	}
	~Class() {
		while (!students.isEmpty()) {
			students.pop();
		}
	}
	std::string getClassID() {
		return classID;
	}
	std::string getClassName() {
		return className;
	}
	void setClassID(std::string classID) {
		this->classID = classID;
	}
	void setClassName(std::string className) {
		this->className = className;
	}

	//Student
	void addStudent(Student student) {
		students.push(student);
	}
	Stack<Student> getStudents() {
		return students;
	}
};