#include "BuiltClasses.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1700, 950), "Course management system", sf::Style::Close | sf::Style::Titlebar);
	Activity activity;
	bool invalidLogin = false;
	while (window.isOpen())
	{
		switch (activity.type)
		{
		case 0:
			activity.initLoginWindow(window, invalidLogin);
			break;
		case 1:
			activity.initHomePageStudentWindow(window);
			break;
		case 2:
			activity.initInformationStudentWindow(window);
			break;
		case 3:
			activity.changePasswordStudentWindow(window);
			break;
		case 4:
			activity.viewCourseStudentWindow(window);
			break;
		case 5:
			activity.viewScoreStudentWindow(window);
			break;
		case 11:
			activity.initHomePageStaffWindow(window);
			break;
		case 12:
			activity.initInformationStaffWindow(window);
			break;
		case 13:
			activity.changePasswordStaffWindow(window);
			break;
		default:
			break;
		}

	}

	return 0;
}
//
//int main() {
//	Course course("data/courses/22_23/Semester3/CS162");
//
//	Student student("23CTT1045");
//
//	course.addStudent(student);
//	course.pressEnter();
//
//	vector<Student> stu = course.getStudiedStudent();
//
//	for (int i = 0; i < stu.size(); ++i)
//		std::cout << stu[i].getID() << std::endl;
//
//	return 0;
//}
