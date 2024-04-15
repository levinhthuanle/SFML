#pragma once

#include "Requirement.h"
#include "Student.h"
#include "Vector.h"
#include "FileNFolder.h"

class Class {
private:
	std::string classID, SchoolYear;
    vector<Student> students;

public:
	Class() {}

	
	Class(std::string classID) {
		this->classID = classID;
	}

	Class(std::string classID, std::string SchoolYear) {
		this->classID = classID;
		this->SchoolYear = SchoolYear;
	}
	//get a class from a special csv file (for task 4)
	Class(fsys::path filepath)
	{
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