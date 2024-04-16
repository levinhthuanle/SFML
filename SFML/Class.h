#pragma once

#include "Student.h"
#include "FileNFolder.h"

class Class {
public:
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
			getStudent(classPath);
			
		}
	}

	//get a class from a special csv file (for task 4)
	void getStudent (fsys::path filepath)
	{
		classPath = filepath;
		std::string cls = filepath.u8string();
		classID = cls.substr(cls.find_last_of('/') + 1);

		csvFile studentList(filepath);
		studentList.readFile();

		for (int i = 0; i < studentList.cnt.size(); ++i)
		{
			vector<std::string> info(6);
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

	//static vector<Class> getAllClassName() {
	//	vector < std::string> temp;
	//	vector <Class> allClass;
	//	fsys::path student("data/student");

	//	std::string className;

	//	for (auto const& dir_entry : std::filesystem::directory_iterator{ student })
	//	{
	//		className = dir_entry.path().generic_string();
	//		

	//		className = className.substr(className.find_last_of('/') + 1);

	//		temp.push_back(className);
	//	}
	//	temp.decrease_sort();
	//	for (int i = 0; i < temp.size(); ++i)
	//	{
	//		allClass.push_back(Class(temp[i]));
	//	}

	//	return allClass;
	//}
};

