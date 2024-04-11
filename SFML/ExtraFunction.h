#pragma once
#include "Requirement.h"
#include "Components.h"
#include "User.h"
struct EF {
	static std::string getDateTime();
};

void getSubjectData(User& user, fsys::path url);

int checkLoginType(User& user);

bool changePassword(User& user, std::string oldPassword, std::string newPassword, std:: string cfNewPassword);


vector<std::string> getYearFolder();

template<class T>
const T& max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}
template<class T>
const T& min(const T& a, const T& b)
{
    return (a > b) ? b : a;
}


template<class T, class Compare>
const T& max(const T& a, const T& b, Compare comp)
{
    return (comp(a, b)) ? b : a;
}
template<class T, class Compare>
const T& min(const T& a, const T& b, Compare comp)
{
    return (comp(a, b)) ? a : b;
}



