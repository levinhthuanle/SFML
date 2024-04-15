#pragma once

#include "Requirement.h"
#include "vector.h"
#include "SchoolYear.h"
#include "Class.h"
#include "Student.h"

//writing method for teacher
class teacher
{
// can modify or fix anything 
private:
    vector<SchoolYear> schoolyearlist;
    vector<Class> classlist;
    vector<Student> studentlist;

public:
    teacher() {}
    // at begining of school year
    void createschoolyear(std::string name) {
        SchoolYear sy(name);
        schoolyearlist.push_back(sy);
    }


    // at begining of semester
    void createsemmester() {

    }
    void addcourse() {

	}
    void addstudenttocourse() {

    }
    void removestudentfromcourse() {

	}
};


