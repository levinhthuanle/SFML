#pragma once

#include "Requirement.h"
#include "Student.h"
#include "Vector.h"
#include "FileNFolder.h"

class Class {
private:
	std::string classID;
    vector<Student> students;
	fsys::path classPath = "data/student"; 

public:
	Class() {}

	
	Class(std::string classID) 
	{
		this->classID = classID;
		classPath /= classID; 
		if (fsys::exists(classPath))
		{
			
			Class(classPath);
			
		}
	}

	//get a class from a special csv file (for task 4)
	Class(fsys::path filepath)
	{
		classPath = filepath;
		std::string cls = filepath.generic_string();
		classID = cls.substr(cls.find_last_of('/') + 1, 6);

		csvFile studentList(filepath);
		studentList.readFile();

		for (int i = 0; i < studentList.cnt.size(); ++i)
		{
			vector<std::string> info(7);
			info[0] = classID;
			for (int j = 0; j < 5; ++i)
			{
				info[j + 1] = studentList.cnt[i][j];
			}
			students.push_back(Student(info));
		}

	}
	void addStudent(vector<Student> listOfStudent)
	{
		students = listOfStudent;
	}

	void create()
	{
		fsys::create_directories(classPath); 
		for (int i = 0; i < students.size(); ++i)
		{
			Student& tempStudent = students[i]; 
			tempStudent.studentPath = tempStudent.studentPath / (classID + "/" + tempStudent.getID().substr(6));
			students[i].create();
		}
	}

	

	void readData(fsys::path filepath) {
		classID = "";
		csvFile studentList(filepath);
		studentList.readFile();

		for (int i = 0; i < studentList.cnt.size(); ++i)
		{
			vector<std::string> info(7);
			info[0] = classID;
			for (int j = 0; j < 5; ++i)
			{
				info[j + 1] = studentList.cnt[i][j];
			}
			students.push_back(Student(info));
		}
	}

};