#pragma once
#include "Requirement.h"
#include "FileNFolder.h"
#include "vector.h"


//The structure of the files:
//__info.csv__
//Name,         Teacher,    Credits,    Max Students,   Current Students,   Day,    Session,
//Calculus II,  PTMDuyen,   4,          50,             36,                 Wed,      1,
//
//__score.csv__
//Stu ID,       Class,      Name,       Score,
//23125000      23TT2,      ABCDee      9.9


class Course
{
private:
    std::string id;
    fsys::path folderPath;
    csvFile infoFile;
    csvFile scoreFile;
    vector<std::string> info;               //cnt of the info file (the second row)

    void displayErrorExceedMaxStu() {
        std::cerr << "Max students exceeded.\n";
    }

public:

    vector<vector<std::string>> score;      //cnt of the score file (from the second row)

    Course(){}

    Course(fsys::path motherFolder, std::string id, int maxStu) {
        this->id = id;
        this->folderPath = motherFolder / id;
        createFolder(this->folderPath);

        csvFile inf(folderPath / "info.csv");
        this->infoFile = inf;

        csvFile sco(folderPath / "score.csv");
        this->scoreFile = sco;

        infoFile.readFile();
        this->info = infoFile.cnt[1];       //Get the second row of infoFile

        this->setMaxStu(maxStu);

        scoreFile.readFile();
        long long stuNum = scoreFile.cnt.size();
        if (stuNum > this->getMaxStu()) {
            displayErrorExceedMaxStu();
        }
        else {
            this->setCurStu(stuNum);
            for (int i = 1; i < stuNum; i++) this->score.push_back(scoreFile.cnt[i]);
        }
        
    }

    std::string getID() { return id; }
    fsys::path getPath() { return folderPath; }
    std::string getName() { return info[0]; }
    void setName(std::string name) {
        this->info[0] = name;
    }
    std::string getTeacher() { return info[1]; }
    void setTeacher(std::string teacher) {
        this->info[1] = teacher;
    }
    int getCredit() { return stoi(info[2]); }
    void setCredit(int credit) {
        this->info[2] = std::to_string(credit);
    }
    int getMaxStu() { return stoi(info[3]); }
    void setMaxStu(int maxStu) {
        this->info[3] = std::to_string(maxStu);
    }
    int getCurStu() { return stoi(info[4]); }
    void setCurStu(int curStu) {
        this->info[4] = std::to_string(curStu);
    }
    std::string getDay() { return info[5]; }
    void setDay(std::string day) {
        this->info[5] = day;
    }
    std::string getSession() { return info[6]; }
    void setSession(std::string session) {
        this->info[6] = session;
    }
};