#include "Requirement.h"
int main()
{

   /* sf::RenderWindow window(sf::VideoMode(1700, 950), "Course management system", sf::Style::Close | sf::Style::Titlebar);
    Activity activity;
    while (window.isOpen())
    {
        switch (activity.type)
        {
        case 0:activity.initLoginWindow(window);
            break;
        case 1:activity.initHomePageStudentWindow(window);
            break;
        }
    }*/

    Folder folder("Test");
    Folder sub = folder.createSubFolder("SubTest");
    File subFile = sub.createSubFile("sub.csv");

    return 0;
}
