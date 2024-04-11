#pragma once

#include "Requirement.h"
#include "Student.h"
#include "Vector.h"
#include "FileNFolder.h"

class Class {
private:
	std::string classID;
    vector<Student> students;

public:
	Class() {}

	
	Class(std::string classID) {
		this->classID = classID;
	}

	//get a class from a special csv file (for task 4)
	Class(fsys::path filepath)
	{
		classID = "";
		csvFile studentList(filepath); 
		studentList.readFile(); 
		
		for (int i = 0; i < studentList.content.size(); ++i)
		{
			vector<std::string> info(7); 
			info[0] = classID; 
			for (int j = 0; j < 5; ++i)
			{
				info[j + 1] = studentList.content[i][j]; 
			}
			students.push_back(Student(info)); 
		}

	}

	//~Class() {
	//	while (!students.isEmpty()) {
	//		students.pop();
	//	}
	//}



	std::string getClassID();

	std::string getClassName();

	void setClassID(std::string classID);

	//function to create whole student 
	void createWholeStudentList()
	{
		fsys::create_directories("data/course/" + classID); 
		for (int i = 0; i < students.size(); ++i)
			students[i].create(); 
	}

	//Student
	//void addStudent(Student student) {
	//	students.push(student);
	//}
	//Stack<Student> getStudents() {
	//	return students;
	//}
};