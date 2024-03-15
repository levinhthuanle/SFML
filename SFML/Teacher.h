#pragma once
#include <string>
#include <filesystem>
namespace fsys = std::filesystem; 
class Teacher
{

	void create_sy(std::string name)
	{
		if (!fsys::exists("data/student" + name)) return; 
		fsys::create_directory("data/student" + name);
	}
	void create_student()
	{

	}
};
