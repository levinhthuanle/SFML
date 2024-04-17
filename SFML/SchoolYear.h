#pragma once
#include "Requirement.h"
#include "Semester.h"
#include "Class.h"

class SchoolYear {
public:
	std::string year;
	vector<Semester> semester;
	vector<Class> firstYearClasses;

public:
	SchoolYear() {}

	SchoolYear(std::string year) {
		this->year = year;

		std::string schoolYearDir = "data/courses/" + year;

		for (int i = 1; i <= 3; ++i)
		{
			std::string dir = schoolYearDir + "/Semester" + std::to_string(i);
			fsys::path realDir(dir);
			if (fsys::exists(realDir))
				semester.push_back(Semester(dir));
			else
				break;
		}
	}

	std::string getYear() {
		return year;
	}

	void setYear(std::string year) {
		this->year = year;
	}
	void addsemester(Semester sem)
	{
		for (int i = 0; i < semester.size(); ++i)
		{
			if (semester[i].getName() == sem.getName())
			{
				std::cout << "Semester is existed.";
				return;
			}
		}
		semester.push_back(sem);
		return;
	}
	void addFirstYearClass(Class newClass)
	{
		for (int i = 0; i < firstYearClasses.size(); ++i)
		{
			if (firstYearClasses[i].classID == newClass.classID)
			{
				std::cout << "This class is existed.";
				return;
			}
		}

		firstYearClasses.push_back(newClass);
		return;
	}
	void createNewSchoolYear()
	{

		fsys::create_directories("data/courses" + year);
		for (int i = 0; i < semester.size(); ++i)
		{
			semester[i].create();
		}
	}
	void createFirstYearClass()
	{
		for (int i = 0; i < firstYearClasses.size(); ++i)
		{
			firstYearClasses[i].create(); 
		}
	}

};

static vector<SchoolYear> getExistedSchoolYear()
{
	vector < std::string> classYear;
	vector <SchoolYear> realClassYear; 
	fsys::path course("data/courses");
	std::string yearName;

	for (auto const& dir_entry : std::filesystem::directory_iterator{ course })
	{
		yearName = dir_entry.path().generic_string();

		yearName = yearName.substr(yearName.find_last_of('/') + 1, 5); 
		classYear.push_back(yearName);
	}
	classYear.decrease_sort();
	for (int i = 0; i < classYear.size(); ++i)
	{
		realClassYear.push_back(SchoolYear(classYear[i])); 
	}
	return realClassYear;
	
}
static vector<Course> getAllCourse(vector <SchoolYear>& existingSchoolYear)
{
	vector<Course> allCourse;
	for (int i = 0; i < existingSchoolYear.size(); ++i)
	{
		for (int j = 0; j < existingSchoolYear[i].semester.size(); ++j)
		{
			existingSchoolYear[i].semester[j].loadCourse();
			for (int k = 0; k < existingSchoolYear[i].semester[j].courses.size(); ++k)
				allCourse.push_back(existingSchoolYear[i].semester[j].courses[k]);
		}
	}
	return allCourse;
}

