#pragma once
#include "Requirement.h"

class SchoolYear {
    string year;
    Stack<Semester> semesters;
public:
    SchoolYear(string year) : year(year) {
      
        string directory = "data/" + year;

        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            semesters.push(Semester(entry.path()));
        }
    }
   
};