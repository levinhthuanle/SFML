#include "Requirement.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(1700, 950), "Course management system", sf::Style::Close | sf::Style::Titlebar);
    Activity activity;
    while (window.isOpen())
    {
        switch (activity.type)
        {
        case 0:
            activity.initLoginWindow(window);
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

        default:
            break;
        }

    }

    return 0;
}
