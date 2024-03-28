#pragma once
#include "Requirement.h"

class Course
{
private:
    int id, credits, maxStudents, session1, session2;
    std::string courseID, courseName, teacherName, startDate, endDate;
public:
    Course(int id) : Course() {
        this->id = id;
    }

    Course(int id, std::string courseName) : Course(id) {
        this->courseName = courseName;
    }

    Course(int id, std::string courseID, std::string courseName, std::string teacherName, int credits, int maxStudents, int session1, int session2, std::string startDate, std::string endDate)
        : Course(id, courseName) {
        this->courseID = courseID;
        this->teacherName = teacherName;
        this->credits = credits;
        this->maxStudents = maxStudents;
        this->session1 = session1;
        this->session2 = session2;
        this->startDate = startDate;
        this->endDate = endDate;
    }

    ~Course() {
            
    }
};