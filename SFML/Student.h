#pragma once
#include "Requirement.h"
#include "Vector.h"
#include "FileNFolder.h"

namespace fsys = std::filesystem;

//this class contain ONLY INFORMATION about a student.
class Student
{
public:
	// a vector containing basic information of a student, has 6+ element: 
	// index 0 is class, index  1 is id, index 2 is fullname
	// index 3 is gender, index 4 is DoB, index 5 is social ID. 

	vector<std::string> basic_info;

	//more information about student
	fsys::path studentPath = "data/student";

	Student() {
		for (int i = 0; i < 6; ++i)
			basic_info.push_back("");
	}
	//constructor for teacher to get ID
	Student(std::string ID); // simple construction

	Student(vector<std::string>& fullBasicInfo); //complex construction with full of basic info  

	//method for teacher
	////adding basic information to prepare for creating new folder  

	Student& operator=(const Student& rhs) {
		if (&rhs == this) return *this;
		this->basic_info = std::move(rhs.basic_info);
		this->studentPath = std::move(rhs.studentPath);
		return *this;
	}

	void updateBasic(vector<std::string>& fullBasicInfo);

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
	
	void setClass(std::string cla) {
		basic_info[0] = cla;
	}

	void setID(std::string id) {
		basic_info[1] = id;
	}

	void setFullname(std::string name) {
		basic_info[2] = name;
 	}

	void getScoreBoard();

	bool is_exist()

	{
		return (fsys::exists(studentPath) && !fsys::is_empty(studentPath));
	}
	void self_destroy()
	{
		fsys::remove_all (studentPath);
		basic_info.clear();
	}
	void upgradeFinished(std::string CourseID)
	{
		csvFile allSubject(studentPath / "subject.csv"); 
		allSubject.readFile(); 
		for (int i = 0; i < allSubject.cnt.size() / 9; ++i)
		{
			if (allSubject.cnt[9 * i][0] == CourseID)
			{
				
				std::string& replacing = allSubject.cnt[9 * i + 8][0]; 
				if (replacing[0] == '-')
					replacing = replacing.substr(1); 
				allSubject.writeFile(); 
			}
		}
	}
};


