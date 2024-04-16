#include "Student.h"
#include "FileNFolder.h"

vector<std::string> Student::getUnfinishedCourse()
{
	std::ifstream fin(studentPath); 
	std::string unnecessary; 
	for (int i = 0; i < 4; ++i)
	{
		std::getline(fin, unnecessary);
	}
	std::string classcode;  //class code here means that student will have a class name classcode, equivalent to coursename.
	vector <std::string> course; 
	while (std::getline(fin, classcode))
	{
		if (classcode == "\n") break;
		else course.push_back(classcode); 
	}
	return course;
}

vector<std::string> Student::getFinishedCourse()
{
	{
		std::ifstream fin(studentPath);
		std::string classcode;  //class code here means that student will have a class name classcode, equivalent to coursename.
		vector<std::string> course; 
		while (std::getline(fin, classcode))
		{
			if (classcode == "\n") break;
			else course.push_back(classcode);
		}
		while (std::getline(fin, classcode))
		{
			if (classcode == "\n") break;
			else course.push_back(classcode);
		}
		return course;
	}
}
void Student::getScoreBoard()
{
}
//void Student::create()
//{
//	studentPath = studentPath / classname;
//	if (!fsys::exists(studentPath))
//	{
//		std::cerr << "Don't find out the year";
//		return;
//	}
//	std::string num(id.begin() + 6, id.begin() + 9);
//	studentPath /= num;
//	if (!fsys::exists(studentPath))
//	{
//		std::cerr << "This student have already been added. ";
//		return;
//	}
//	else
//	{
//
//
//		std::ofstream fout;
//		fout.open(studentPath);
//		fout << "123\n" << id << "\n" << fullname << "\n" << classname << "\n";
//		return;
//	}
//}
//Student::Student(User user)
//{
//	fullname = user.fullname;
//	id = user.id;
//	classname = user.className;
//	this->studentPath = user.getUrl();
//
//}
//void updateBasic(std::string name, std::string ID) // takes 2 arguments, if you don't want to input some thing, pass "")
//{
//	fullname = name;
//	id = ID;
//	classname.assign(ID.begin(), ID.begin() + 6);
//}
Student::Student(std::string ID)
{
	for (int i = 0; i < 6; ++i)
		basic_info.push_back("");
	basic_info[1] = ID; 
}
Student::Student(vector<std::string> fullBasicInfo)
{
	basic_info = fullBasicInfo;
	std::string ID = basic_info[1];
	std::string num(ID.begin() + 6, ID.begin() + 9);
	studentPath = studentPath / basic_info[0] / num;
}
Student::Student(User user)
{
	for (int i = 0; i < 6; ++i)
		basic_info.push_back("");
	basic_info[0] = user.className; 
	basic_info[1] = user.id; 
	basic_info[2] = user.fullname;
}
void Student::updateBasic(vector<std::string> fullBasicInfo)
{
	basic_info = fullBasicInfo;
	std::string ID = basic_info[1]; 
	std::string num(ID.begin() + 6, ID.begin() + 9); 
	studentPath = studentPath / basic_info[0] / num; 
}
void Student::create()
{
	
	csvFile studentFile(studentPath); 
	vector<std::string> defaultPass(1,"123"); 
	studentFile.cnt.push_back(defaultPass); 


	for (long long i = 0; i < 6; ++i)
	{
		studentFile.addRow(); 
		studentFile.cnt[i + 1] = vector<std::string>(1,basic_info[i]); 
	}
	studentFile.isCreate(); 
	studentFile.writeFile(); 
	return; 
}

void Student::updateCourse(std::string newcoursename)
{
}
