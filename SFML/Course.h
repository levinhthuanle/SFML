#pragma once
#include "FileNFolder.h"
#include "Requirement.h"
#include "vector.h"


//Run pressEnter function when Proceed Button is click: Save changes to the files
//Run pressBack function when Back Button is click: Discard changes to the files


//The structure of the files:
//__info.csv__
//Name,         Teacher,    Credits,    Max Students,   Current Students,   Day,            Session,
//Calculus II,  PTMDuyen,   4,          50,             36,                 Wed,            1,
//
//__score.csv__
//Stu ID,       Class,      Name,       Practice Score, Midterm Score,      Final Score,    Plus Score, Other Score,    Average Score,
//23125000      23TT2,      ABCDee      9.0             9.8




class Course
{
private:
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

	Course() {}

    Course(fsys::path motherFolder, std::string id, std::string name, std::string teacher, int credit, int maxStu, std::string day, std::string session) {
        this->id = id;
        this->folderPath = motherFolder / id;
        createFolder(this->folderPath);

        csvFile inf(folderPath / "info.csv");
        this->infoFile = inf;
        vector <std::string> infoTit;
        infoTit.setDefault(this->infoTitle);

        csvFile sco(folderPath / "score.csv");
        this->scoreFile = sco;
        vector <std::string> scoreTit;
        scoreTit.setDefault(this->scoreTitle);

        infoFile.readFile();

        scoreFile.readFile();

        setName(name);
        setTeacher(teacher);
        setCredit(credit);
        setMaxStu(maxStu);
        setCurStu(0);
        setDay(day);
        setSession(session);
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
    }


    //Add students by csv file
    bool importStudentsFile(fsys::path filePath) {
        return fsys::copy_file(filePath, this->folderPath / "score.csv");
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
};