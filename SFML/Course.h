#pragma once
#include "Requirement.h"

class Course
{
private:
    int id, credits, maxStudents, session1, session2;
    std::string courseID, courseName, teacherName, startDate, endDate;
    Stack<Student> students;
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
            while (!students.isEmpty()) {
                students.pop();
            }
    }

    int getId() {return id;}

    int getID() { return id; }

    std::string getCourseID() { return courseID; }

    std::string getCourseName() { return courseName; }

    std::string getTeacherName() { return teacherName; }

    int getCredits() { return credits; }

    void setFirstSession(int session1) { this->session1 = session1; }

    int getFirstSession() { return session1; }

    void setSecondSession(int session2) { this->session2 = session2; }

    int getSecondSession() { return session2; }

    //Student
    void addStudent(Student student) {
		students.push(student);
	}
    Stack<Student> getStudents() {
        return students;
    }
    
};