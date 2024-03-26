#pragma once
#include "Requirement.h"
class Date {
private:
    string date;

public:
    Date(string date) {
        this->date = date;
    }

    int getYear() {
        return stoi(date.substr(6));
    }
};