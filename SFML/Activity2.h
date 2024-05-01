#pragma once
#include "Subject.h"
#include "Components.h"
#include "vector.h"
#include "Semester.h"
#include "tinyfiledialogs/tinyfiledialogs.h"
//I assume that this class create sub-activity for student. 

class Activity2
{
public:

	Activity2() {

	}
	static bool confirm(std::string content);

	static void popup(std::string content);

	static int drawScoreBoard(Course& course, sf::RenderWindow& window, sf::Font& font, int displayFrom, int displayLimit);
	//courseInformationStudent(unfinBtn[i].cnt)
	static void courseInformationStudent(Subject& subject);

	static void createNewSchoolYearStaff(vector<SchoolYear>& existedSchoolYear);

	static void createSemesterStaff(Semester & semester);

	static void viewAllCourseStaff(vector<SchoolYear>& schoolyear);

	static void viewCourseInSemester(Semester& semester);

	static void addCourse(Semester& semester);

	static void courseInformation(Semester& semester, Course& course);

	static void addStudentToCourse(Course& course);

	static void importStudentList(Course& course);

	static void removeStudentFromCourse(Course& course);

	static void updateCourseInformation(Course& course);

	static void viewCourseStudentList(Course& course);

	static void viewOneClass(Class& oneclass);

	static void viewAllClassStaff(vector<Class>& allClass);

	static void addClassStaff(std::string lastYear, Class &tempClass);

	static void removeStudent(Class& oneclass);

	static void addStudent(Class& oneclass);

	static void scoreBoardOfClassStaff(Class& oneclass);

	static void importScoreCourseStaff(Semester& semester, Course& course);

	static void exportStudentList(Course& course);

	static void exportScoreBoard(Course& course);

	static void viewScoreboardStudent(vector<Subject>& listOfUnfinCourse);

	static void changeStudentScore(vector<std::string>& studentInfor);
};

bool isSame(std::string a, std::string b);