#include "Requirement.h"
int main()
{
    //Activity activity;

    //activity.initLoginWindow();

    Folder folder("Test");
    Folder sub = folder.createSubFolder("SubTest");
    File file = sub.createSubFile("test.txt");
    file.open();
    file.write("123");
    file.close();

    return 0;
}
