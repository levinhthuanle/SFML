#pragma once
#include "Requirement.h"
class Date {
private:
    std::string date;

public:
    Date() {}

    Date(std::string date) {
        this->date = date;
    }

    int getYear() {
        return stoi(date.substr(6));
    }
};