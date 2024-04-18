#include "Student.h"
#include "FileNFolder.h"

vector<std::string> Student::getUnfinishedCourse()
{
	std::ifstream fin(studentPath); 
	std::string unnecessary; 
	for (int i = 0; i < 6; ++i)
		getline(fin, unnecessary);
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

Student::Student(std::string ID)
{
	for (int i = 0; i < 6; ++i)
		basic_info.push_back("");
	std::string clss = ID.substr(0, 6); 
	std::string order = ID.substr(6); 
	basic_info[0] = clss; 
	basic_info[1] = ID; 

	studentPath /= clss + "/" + order;
	if (fsys::exists(studentPath) && !fsys::is_empty(studentPath))
	{
		std::string studentPathString = studentPath.generic_string();
		studentPathString += "/" + order + ".csv";


		for (auto& c : studentPathString)
			if (c == 92) c = '/';
		std::ifstream fin(studentPathString);
		for (int i = 0; i < 6; ++i)
		{
			getline(fin, basic_info[i]);
			std::cout << basic_info[i];
		}
	}
}
Student::Student(vector<std::string> fullBasicInfo)
{
	basic_info = fullBasicInfo;
	std::string ID = basic_info[1];
	std::string num(ID.begin() + 6, ID.begin() + 9);
	studentPath = studentPath / basic_info[0] / num;
}
//Student::Student(User user)
//{
//	for (int i = 0; i < 6; ++i)
//		basic_info.push_back("");
//	basic_info[0] = user.className; 
//	basic_info[1] = user.id; 
//	basic_info[2] = user.fullname;
//}
void Student::updateBasic(vector<std::string> fullBasicInfo)
{
	basic_info = fullBasicInfo;
	std::string ID = basic_info[1]; 
	std::string num(ID.begin() + 6, ID.begin() + 9); 
	studentPath = studentPath / basic_info[0] / num; 
}
void Student::create()
{
	std::ofstream fout(studentPath / "password.txt"); 
	fout << "!23";
	fout.close(); 

	csvFile studentFile(studentPath/ basic_info[1].substr(6));


	for (long long i = 0; i < 6; ++i)
	{
		studentFile.addRow(); 
		studentFile.cnt[i] = vector<std::string>(1,basic_info[i]); 
	}
	studentFile.isCreate(); 
	studentFile.writeFile(); 
	return; 
}

void Student::updateCourse(std::string newcoursename)
{
}
