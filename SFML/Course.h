#pragma once
#include "FileNFolder.h"
#include "Requirement.h"
#include "Student.h"
#include "vector.h"
#include "ExtraFunction.h"
//Run pressEnter function when Proceed Button is click: Save changes to the files
//Run pressBack function when Back Button is click: Discard changes to the files


//The structure of the files:
//__info.csv__
//Name,         Teacher,    Credits,    Max Students,   Current Students,   Day,            Session,
//Calculus II,  PTMDuyen,   4,          50,             36,                 Wed,            1,
//
//__score.csv__
//Stu ID,       Class,      Name,       Practice Score, Midterm Score,      Final Score,    Plus Score, Other Score,    Average Score,
//23CTT1045     23TT2,      ABCDee      9.0             9.8



class Course
{
public:
	std::string id;
	fsys::path folderPath;
	csvFile infoFile;
	csvFile scoreFile;
	vector<vector<std::string>>& info = infoFile.cnt;


	//Just default files' title
	std::string infoTitle[7] = { "Name", "Teacher", "Credits", "Max Students", "Current Student", "Day", "Session" };
	std::string scoreTitle[9] = { "Student ID", "Class", "Full Name", "Practice Score", "Midterm Score", "Final Score", "Plus Score", "Other Score", "Average Score" };


	void displayErrorExceedMaxStu() {
		std::cerr << "Max students exceeded.\n";
	}


public:

	vector<vector<std::string>>& score = scoreFile.cnt;
	Course& operator=(const Course& b) {
		if (this == &b) return *this;
		this->id = b.id;
		this->folderPath = b.folderPath;
		this->infoFile = b.infoFile;
		this->scoreFile = b.scoreFile;
		return *this;
	}

	Course() {}


	Course(fsys::path motherFolder, std::string id, std::string name, std::string teacher, int credit, int maxStu, std::string day, std::string session) {
		this->id = id;
		this->folderPath = motherFolder / id;
		createFolder(this->folderPath);

		csvFile inf(folderPath / "info.csv");
		this->infoFile = inf;
		vector <std::string> infoTit;
		infoTit.setDefault(7, this->infoTitle);
		info.push_back(infoTit);

		csvFile sco(folderPath / "score.csv");
		this->scoreFile = sco;
		vector <std::string> scoreTit;
		scoreTit.setDefault(9, this->scoreTitle);
		score.push_back(scoreTit);

		setName(name);
		setTeacher(teacher);
		setCredit(credit);
		setMaxStu(maxStu);
		setCurStu(0);
		setDay(day);
		setSession(session);

		infoFile.writeFile();
		scoreFile.writeFile();

        setName(name);
        setTeacher(teacher);
        setCredit(credit);
        setMaxStu(maxStu);
        setCurStu(0);
        setDay(day);
        setSession(session);
    }

	Course(fsys::path folderPath)
	{
		std::string courseID = folderPath.generic_string();
		for (auto& c : courseID)
			if (c == 92) c = '/';
		courseID = courseID.substr(courseID.find_last_of('/') + 1);
		this->id = courseID;
		csvFile inf(folderPath / "info.csv");
		this->infoFile = inf;
		csvFile sco(folderPath / "score.csv");
		this->scoreFile = sco;
		infoFile.readFile();
		scoreFile.readFile();
		if (infoFile.cnt.size() <= 1) return;
		setName(infoFile.cnt[1][0]);
		setTeacher(infoFile.cnt[1][1]);
		setCredit(stoi(infoFile.cnt[1][2]));
		setMaxStu(stoi(infoFile.cnt[1][3]));
		setCurStu(stoi(infoFile.cnt[1][4]));
		setDay(infoFile.cnt[1][5]);
		setSession(infoFile.cnt[1][6]);
	}

	void pressEnter() {                                         //When press Enter or Continue Button after some changes, this function runs, save changes to the file.
		infoFile.writeFile();
		scoreFile.writeFile();
	}

	void pressBack() {
		infoFile.readFile();
		scoreFile.writeFile();                                  //When press Back Button, this function runs, discard the changes.
	}


	std::string getID() { return id; }
	fsys::path getPath() { return folderPath; }
	std::string getName() { return info[1][0]; }
	void setName(std::string name) {
		this->info[1][0] = name;
	}

	std::string getTeacher() { return info[1][1]; }

	void setTeacher(std::string teacher) {
		this->info[1][1] = teacher;
	}

	int getCredit() { return stoi(info[1][2]); }

	void setCredit(int credit) {
		this->info[1][2] = std::to_string(credit);
	}

	int getMaxStu() { return stoi(info[1][3]); }

	void setMaxStu(int maxStu) {
		this->info[1][3] = std::to_string(maxStu);
	}

	int getCurStu() { return stoi(info[1][4]); }

	void setCurStu(int curStu) {
		this->info[1][4] = std::to_string(curStu);
	}

	std::string getDay() { return info[1][5]; }

	void setDay(std::string day) {
		this->info[1][5] = day;
	}

	std::string getSession() { return info[1][6]; }

	void setSession(std::string session) {
		this->info[1][6] = session;
	}

	void subjectByCourse(Subject& subject, User& user) {
		subject.completed = false;
		subject.courseId = this->getID();
		subject.courseName = this->getName();
		subject.teacherName = this->getTeacher();
		subject.credits = this->getCredit();
		subject.numOfStudents = this->getCurStu();
		subject.sessions = static_cast<int>(this->getSession()[1]);
		subject.days = this->getDay();
		subject.time = "Time";
		subject.midScore = subject.practiceScore = subject.plusScore = subject.otherScore = subject.finalScore = subject.aveScore = -1;

		subject.id = user.getUsername();
	}

	//Add one student

	bool addStudent(Student& student) {
		if (getCurStu() == getMaxStu()) {
			displayErrorExceedMaxStu();
			return false;
		}
		else {
			setCurStu(getCurStu() + 1);
			vector<std::string> newStu;
			newStu.push_back(student.getID());
			newStu.push_back(student.getClass());
			newStu.push_back(student.getFullname());
			for (int i = 0; i < 6; i++)
				newStu.push_back("");
			score.push_back(newStu);
			return true;
		}

		User user(student);
		getSubjectData(user, user.url / "subject.csv");

		Subject subject;
		subjectByCourse(subject, user);
		user.listOfUnfinCourse.push_back(subject);
		user.updateSubjectData();
	}


	//Add students by csv file
	bool importStudentsFile(fsys::path filePath) {
		csvFile file(filePath);
		file.readFile();
		if (file.cnt.size() > this->getMaxStu()) {
			displayErrorExceedMaxStu();
			return false;
		}
		score.clear();
		vector<Student> stuList = this->getStudiedStudent();
		for (Student stu : stuList) {
			this->addStudent(stu);
		}
		return true;
	}

	//Export scoreboard file
	void exportScoreBoard(fsys::path& filePath) {
		csvFile file(filePath);
		fsys::copy_file(this->folderPath / "score.csv", filePath);
	}

	//Export student list
	void exportStudentList(fsys::path& filePath) {
		csvFile file(filePath);
		vector <std::string> row;
		for (int i = 0; i < this->getCurStu(); ++i) {
			for (int j = 0; j < 3; j++) {
				row.push_back(score[i + 1][j]);
			}
			file.cnt.push_back(row);
		}
		file.writeFile();
	}
	//create new course folder.
	void create()
	{
		fsys::create_directories(folderPath); 
		infoFile.writeFile(); 
		scoreFile.writeFile(); 
		std::cout << "Done creating course folder."; 
		return; 
	}

	//Get Student list
	vector<Student> getStudiedStudent()
	{
		vector<Student> studiedStudent; 
		for (int i = 1; i < score.size(); ++i)
		{
			Student tempStudent(score[i][0]);
			if (!tempStudent.is_exist())
			{
				std::cerr << "A student here is not existed."; 
				break; 
			}
			studiedStudent.push_back(tempStudent); 
		}
		return studiedStudent; 
	}
};
