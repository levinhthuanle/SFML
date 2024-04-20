#pragma once
#include "Subject.h"
#include "Components.h"
#include "vector.h"
#include "Semester.h"

//I assume that this class create sub-activity for student. 
const sf::Color BLACK = sf::Color(18, 2, 2);
const sf::Color GREEN = sf::Color(81, 161, 147);
const sf::Color ORANGE = sf::Color(218, 110, 50);
const sf::Color RED = sf::Color(144, 44, 44);
class Activity2
{
public:

	Activity2() {

	}
	static bool confirm(std::string content);

	static void popup(std::string content);

	//courseInformationStudent(unfinBtn[i].cnt)
	static void courseInformationStudent(Subject& subject);

	static void createNewSchoolYearStaff();

	static void createSemesterStaff(Semester & semester);

	static void viewAllCourseStaff(vector<Course>& course);

	static void viewCourseInSemester(Semester& semester);

	static void addCourse(Semester& semester);

	static void courseInformation(Semester& semester, Course& course);

	static void updateCourseInformation(Course& course);

	static void viewCourseStudentList(Course& course);

	static void viewOneClass(Class& oneclass);

	static void viewAllClassStaff(vector<Class>& allClass);

	static void addClassStaff(std::string lastYear, Class &tempClass);

	static void removeStudent(Class& oneclass);

	static void addStudent(Class& oneclass);

	static void scoreBoardOfClassStaff(Class& oneclass);
};

