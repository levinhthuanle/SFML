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
	//load a semester from a existed directory
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
	Semester(std::string latestYear, std::string name)
	{
		this->year = latestYear; 
		this->name = name; 
		semesterPath = "data/courses/" + latestYear  + "/" + name;
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

	fsys::path getPath() {
		return semesterPath;
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

	void addCourse(Course& course) 
	{
		
		courses.push_back(course); 

	}

	void removeCourse(Course& course) {
		std::error_code errorCode;
		if (!fsys::remove_all(semesterPath/course.getID(), errorCode)) {
			std::cout << errorCode.message() << std::endl;
		}
		else {
			course.deleteCourse();
			vector<Student> stuList = course.getStudiedStudent();
			for (Student stu : stuList) {
				User user(stu);
				getSubjectData(user, user.url / "subject.csv");
				vector<Subject>& unFinSub = user.listOfUnfinCourse;
				for (int j = 0; j < unFinSub.size(); ++j) {
					if (unFinSub[j].courseId == course.getID()) {
						unFinSub[j].deleteSubject();
						for (int k = j; k < unFinSub.size()-1; ++k)
							unFinSub[k] = unFinSub[k + 1];
						unFinSub.pop_back();
						user.updateSubjectData();
						return;
					}
				}
				vector<Subject>& finSub = user.listOfFinCourse;
				for (int j = 0; j < finSub.size(); ++j) {
					if (finSub[j].courseId == course.getID()) {
						finSub[j].deleteSubject();
						for (int k = j; k < finSub.size()-1; ++k)
							finSub[k] = finSub[k + 1];
						finSub.pop_back();
						user.updateSubjectData();
						return;
					}
				}
			}
		}
	}

	bool is_exist()
	{
		return fsys::exists(semesterPath);
	}
	void create()
	{
		fsys::create_directories(semesterPath);
		std::ofstream fout;
		fout.open(semesterPath / "start_end_time.txt");
		if (!fout.is_open())
		{
			std::cerr << "Can not open file.";
			return;
		}
		fout << startDate.date << "\n" << endDate.date; 
		fout.close(); 
	}
};