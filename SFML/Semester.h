#pragma once
#include "Requirement.h"
#include "Date.h"
#include "Vector.h"
#include "Course.h"

class Semester {
public:
	fsys::path semesterPath;
	std::string name = "";
	std::string year = ""; 
	Date startDate;
	Date endDate;
	vector<Course> courses;
public:
	Semester() {};

	Semester(std::string directory) 
	{
		semesterPath = directory; 
		auto t = directory.find_last_of("/"); 
		name = directory.substr(t + 1);
		year = directory.substr(t - 5, 5);
		std::ifstream file(directory + "/start_end_time.txt");
		std::string line;
		std::getline(file, line);
		startDate = Date(line);
		std::getline(file, line);
		endDate = Date(line);

		//for (const auto& entry : std::filesystem::directory_iterator(directory + "/courses")) {
		//    courses.push(Course(entry.path()));
		//}
	}
	 

	~Semester() {
		
	}

	std::string getName() {
		return name;
	}

	Date getStartDate() {
		return startDate;
	}

	Date getEndDate() {
		return endDate;
	}

	vector<Course> getCourses() {
		return courses;
	}
	void loadCourse()
	{
		for (auto const& dir_entry : std::filesystem::directory_iterator{semesterPath})
		{
			std::string coursename = dir_entry.path().generic_string(); 
			std::string classname = coursename.substr(coursename.find_last_of('/') + 1); 
			if (classname == "start_end_date.txt") continue; 
			else
			{
				Course tempcourse(semesterPath / classname);

				courses.push_back(tempcourse);
			}

		}
	}

	void addCourse(Course course) 
	{
		courses.push_back(course); 

	}

	void removeCourse(Course course) 
	{
		for (int i = 0; i < courses.size(); ++i)
		{
			if (course.getID() == courses[i].getID())
			{
				std::error_code errorCode;
				if (!std::filesystem::remove(semesterPath/course.getID(), errorCode)) {
					std::cout << errorCode.message() << std::endl;
				}
				return; 
			}
		}
	}

	void save() {
	    //std::ofstream file("semesters/" + name + "/start_end_time.txt");
	    //file << startDate.toString() << std::endl;
	    //file << endDate.toString() << std::endl;
	    //file.close();
	    //std::filesystem::create_directory("semesters/" + name + "/courses");
	    //while (!courses.empty()) {
	    //    courses.top().save();
	    //    courses.pop();
	    //}
	}
};