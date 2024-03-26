#include "Requirement.h"

class Semester {
    string name;
    Date startDate;
    Date endDate;
    //Stack<Course> courses;
public:
    Semester(string directory) {
 
        name = directory.substr(directory.find_last_of("/") + 1);
        std::ifstream file(directory + "/start_end_time.txt");
        std::string line;
        std::getline(file, line);
        startDate = Date(line); 
        std::getline(file, line);
        endDate = Date(line);

        //for (const auto& entry : std::filesystem::directory_iterator(directory + "/courses")) {
        //    courses.push(Course(entry.path()));
        //}
    }

};