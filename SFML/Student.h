#pragma once
#include "Requirement.h"
#include "Vector.h"
#include "User.h"
namespace fsys = std::filesystem;

//this class contain ONLY INFORMATION about a student.
class Student
{
private:



	// a vector containing basic information of a student, has 6+ element: 
	// index 0 is class, index  1 is id, index 2 is fullname
	// index 3 is gender, index 4 is DoB, index 5 is social ID. 
	// from index 5 are courses of that student
	vector<std::string> basic_info;

	//more information about student
public:
	fsys::path studentPath = "data/student";
	Student() {
		for (int i = 0; i < 6; ++i)
			basic_info.push_back("");
	}

	//constructor for teacher to get ID
	Student(std::string ID); // simple construction

	Student(vector<std::string> fullBasicInfo); //complex construction with full of basic info  

	//constructor for student running the file. 
	Student(User user);

	//method for teacher
	////adding basic information to prepare for creating new folder  

	void updateBasic(vector<std::string> fullBasicInfo);

	////create new student
	void create();

	////update from existing information.
	void updateCourse(std::string newcoursename);

	//method for student
	vector<std::string> getUnfinishedCourse();

	vector<std::string> getFinishedCourse();

	std::string getClass() { return basic_info[0]; }
	std::string getID() { return basic_info[1]; }
	std::string getFullname() { return basic_info[2]; }
	std::string getGender() { return basic_info[3]; }

	void getScoreBoard();
};


