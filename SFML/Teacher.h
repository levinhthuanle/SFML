#pragma once

#include "Requirement.h"
//#include "Vector.h"
//
//
//namespace fsys = std::filesystem; 
//
//void createMultipleDirectories(fsys::path path, vector<std::string> list_name);
////Create multiple directories based on the linked list which a teacher input for classes in school year // student in a class.
//
////std::stringstream readFile(fsys::path filepath);
//vector<std::stringstream> readFileFromFolder(fsys::path filepath);
//
//vector<std::string> getYearFolder(); 
//
////Multiple definition of createMultipleDirectory and readFile to fix "identifier not found" (C3861). Don't know why
//
//class Teacher
//{
//private:
//	void createInfoStudent() // use to create default folder in "student" folder.
//	{
//
//	}
//public:
//	Teacher() {}
//
//	void createSy(std::string name)
//	{
//		fsys::create_directories(name); 
//		return; 
//	}
//
//	bool createClass(std::string schoolYear, std::stringstream classTypes) //create multiple class based on one school year (for example: 23) and a list of type of class (for example : TT1, CLC2).
//	{
//		std::string cls; 
//		vector<std::string> classList; 
//		while (classTypes >> cls)
//		{
//			cls = schoolYear + cls; 
//			if (cls.size() < 5 && cls.size() > 6) return false;
//			classList.push_back(cls); 
//		}
//		
//		createMultipleDirectories("data/student" , classList);
//		classList.pop_back(); 
//		return true; 
//	}
//	bool createClass(std::stringstream classNames) //create multiple class with full name, for example: 23TT1, 22CLC2
//	{
//		std::string cls;
//		vector<std::string> classListOfName;
//		while (classNames >> cls)
//		{
//			if (cls.size() < 5 && cls.size() > 6) return false; 
//			classListOfName.push_back(cls);
//		}
//		createMultipleDirectories("data/student", classListOfName);
//		classListOfName.pop_back();
//		return true;
//		
//	}
//	
//	bool createStudent(fsys::path className, std::stringstream student)
//	{
//
//		return true; 
//	}
//
//	
//	bool createCourse(fsys::path course)
//	{
//		return true; 
//	}
//
//	
//};

//writing method for teacher
class Teacher
{

};


