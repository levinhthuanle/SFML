#pragma once
#include "Date.h"
#include "Course.h"

class Semester {
private:
	fsys::path semesterPath;
	
public:
	std::string name = "";
	std::string year = "";
	Date startDate;
	Date endDate;
	vector<Course> courses;
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
	}
	 

	~Semester() {
		
	}

	Semester& operator=(const Semester& rhs) {
		this->semesterPath = rhs.semesterPath;
		this->name = rhs.name;
		this->year = rhs.year;
		this->startDate = rhs.startDate;
		this->endDate = rhs.endDate;
		this->courses = rhs.courses;
		return *this;
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
			for (auto& c : coursename)
				if (c == 92) c = '/';
			std::string classname = coursename.substr(coursename.find_last_of('/') + 1); 
			if (classname == "start_end_time.txt") 
				continue; 
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

	void create() 
	{
		fsys::create_directories(semesterPath); 

		for (int i = 0; i < courses.size(); ++i)
		{
			courses[i].create(); 
		}
		std::cout << "\nDone creating folder semester."

	}
};