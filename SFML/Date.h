#pragma once
#include "Requirement.h"
class Date {
private:
    int daysInMonth[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 }; 

public:
    std::string date;
    int day = 0, month = 0, year = 0;
    Date() {}
    
    Date(std::string date) {
        if (date.size() < 6) return; 
        this->date = date;
        day = std::stoi(date.substr(0, 2));
        month = std::stoi(date.substr(3, 2));
        year = std::stoi(date.substr(6));
    }

    Date& operator=(const Date& rhs) {
        this->date = rhs.date;
        return *this;
        day = rhs.day; 
        month = rhs.month; 
        year = rhs.year; 
    }
    bool is_valid()
    {
        bool isLeap = (year % 4 == 0) && (!(year % 100 == 0) || year % 400 == 0); 
        if (month < 1 || month > 12 || day < 0 || (day > daysInMonth[month -1] + (month == 2) ? isLeap : 0))
            return false;
        else return true; 
        
    }
    bool operator< (Date& anotherDate)
    {
        
        if (year != anotherDate.year) return (year < anotherDate.year);
        else if (month != anotherDate.month) return month < anotherDate.month;
        else return (day < anotherDate.day); 
    }
    int getYear() {
        return stoi(date.substr(6));
    }
};