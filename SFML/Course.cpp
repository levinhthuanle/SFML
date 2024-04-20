#include "Course.h"

Course& Course::operator=(const Course& b){
	if (this == &b) return *this;
	this->id = b.id;
	this->folderPath = b.folderPath;
	this->infoFile = b.infoFile;
	this->scoreFile = b.scoreFile;
	return *this;
}

Course::Course(fsys::path motherFolder, std::string id, std::string name, std::string teacher, int credit, int maxStu, std::string day, std::string session)
{
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

	vector<std::string> infoRow;
	for (int i = 0; i < 7; ++i)
		infoRow.push_back("");
	info.push_back(infoRow);

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

Course::Course(fsys::path folderPath){
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
	if (infoFile.cnt.size() <= 1) 
		return;

	setName(infoFile.cnt[1][0]);
	setTeacher(infoFile.cnt[1][1]);
	setCredit(stoi(infoFile.cnt[1][2]));
	setMaxStu(stoi(infoFile.cnt[1][3]));
	setCurStu(stoi(infoFile.cnt[1][4]));
	setDay(infoFile.cnt[1][5]);
	setSession(infoFile.cnt[1][6]);
}

void Course::subjectByCourse(Subject& subject, User& user){
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

bool Course::addStudent(Student& student){
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
	}

	User user(student);
	getSubjectData(user, user.url / "subject.csv");

	Subject subject;
	subjectByCourse(subject, user);
	user.listOfUnfinCourse.push_back(subject);
	user.updateSubjectData();
	return true;
}

bool Course::removeStudent(std::string id){
	for (int i = 0; i < score.size(); i++) {
		if (score[i][0] == id) {
			Student stu(id);
			User user(stu);
			getSubjectData(user, user.url / "subject.csv");
			vector<Subject>& unFinSub = user.listOfUnfinCourse;
			for (int j = 0; j < unFinSub.size(); ++j) {
				if (unFinSub[j].courseId == this->getID()) {
					unFinSub[j].deleteSubject();
					for (int k = j; k < unFinSub.size(); ++k)
						unFinSub[k] = unFinSub[k + 1];
					unFinSub.pop_back();
					user.updateSubjectData();
					return true;
				}
			}
			vector<Subject>& finSub = user.listOfFinCourse;
			for (int j = 0; j < finSub.size(); ++j) {
				if (finSub[j].courseId == this->getID()) {
					finSub[j].deleteSubject();
					for (int k = j; k < finSub.size(); ++k)
						finSub[k] = finSub[k + 1];
					finSub.pop_back();
					user.updateSubjectData();
					return true;
				}
			}
		}
	}
	displayErrorStudentNotFound();
	return false;
}

bool Course::importStudentsFile(fsys::path filePath){
	csvFile file(filePath);
	file.readFile();
	if (file.cnt.size() > this->getMaxStu()) {
		displayErrorExceedMaxStu();
		return false;
	}
	score = file.cnt;
	vector<Student> stuList = this->getStudiedStudent();
	score.clear();
	for (Student stu : stuList) {
		this->addStudent(stu);
	}
	return true;
}

void Course::exportStudentList(fsys::path& filePath){
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

void Course::create(){
	fsys::create_directories(folderPath);
	infoFile.writeFile();
	scoreFile.writeFile();
	std::cout << "Done creating course folder.";
	return;
}

vector<Student> Course::getStudiedStudent(){
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