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
		if (fsys::exists(classPath) && !fsys::is_empty(classPath))
		{
			for (const auto& dir_entry : std::filesystem::directory_iterator{ classPath })
			{
				std::string stringPath = dir_entry.path().generic_string(); 
				std::string ID = stringPath.substr(stringPath.find_last_of('/') + 1);
				students.push_back(Student(classID + ID));
			}
		}

	}

	//get a class from a special csv file (for task 4)
	bool getStudent (fsys::path filepath)
	{
		// need to check this again, carefully. 
		csvFile studentList(filepath);
		studentList.readFile();

		for (int i = 1; i < studentList.cnt.size(); ++i)
		{
			vector<std::string> info(6);
			info[0] = classID;
			for (int j = 0; j < 5; ++j)
			{
				info[j+1] = studentList.cnt[i][j];
			}
			students.push_back(Student(info));
		}
		return true; 
	}
	void addStudent(vector<Student> listOfStudent)
	{
		students = listOfStudent;
	}
	bool is_existed()
	{
		return fsys::exists(classPath); 
	}
	void create()
	{
		fsys::create_directories(classPath); 
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

static vector<Class> getAllClassName() {
	vector < std::string> temp;
	vector <Class> allClass;
	fsys::path student("data/student");

	std::string className;

	for (auto const& dir_entry : std::filesystem::directory_iterator{ student })
	{
		className = dir_entry.path().generic_string();


		className = className.substr(className.find_last_of('/') + 1);

		temp.push_back(className);
	}
	temp.decrease_sort();
	for (int i = 0; i < temp.size(); ++i)
	{
		allClass.push_back(Class(temp[i]));
	}

	return allClass;
}
