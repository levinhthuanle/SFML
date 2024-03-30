//#pragma once
//#include "Requirement.h"
//
//
//namespace fsys = std::filesystem; 
//
//void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);
////Create multiple directories based on the linked list which a teacher input for classes in school year // student in a class.
//
////std::stringstream readFile(fsys::path filepath);
// Stack <std::stringstream> readFileFromFolder(fsys::path filepath);
//
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
//	void createSy(std::string name)
//	{
//		fsys::create_directories(name); 
//		return; 
//	}
//	bool createClass(std::string schoolYear, std::stringstream classTypes) //create multiple class based on one school year (for example: 23) and a list of type of class (for example : TT1, CLC2).
//	{
//		std::string cls; 
//		Stack <std::string> classList; 
//		while (classTypes >> cls)
//		{
//			cls = schoolYear + cls; 
//			if (cls.size() < 5 && cls.size() > 6) return false;
//			classList.push(cls); 
//		}
//		
//		createMultipleDirectories("data/student" , classList);
//		classList.del(); 
//		return true; 
//	}
//	bool createClass(std::stringstream classNames) //create multiple class with full name, for example: 23TT1, 22CLC2
//	{
//		std::string cls;
//		Stack <std::string> classListOfName;
//		while (classNames >> cls)
//		{
//			if (cls.size() < 5 && cls.size() > 6) return false; 
//			classListOfName.push(cls);
//		}
//		createMultipleDirectories("data/student", classListOfName);
//		classListOfName.del();
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
//
//
