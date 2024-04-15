#pragma once
#include "Requirement.h"
#include "Semester.h"
#include "Class.h"

class SchoolYear {
private:
	std::string year;
	vector<Semester> sem; 
	vector<Class> firstYearClasses;

public:
	SchoolYear() {}

	SchoolYear(std::string year) {
		this->year = year;
		
		std::string schoolYearDir = "data/courses/" + year; 
		
		for (int i = 1; i <= 3; ++i)
		{
			std::string dir = schoolYearDir + "/Semester" + static_cast<char>(i + '0');
			fsys::path realDir(dir); 
			if (fsys::exists(realDir))
				sem.push_back(Semester(dir));
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


