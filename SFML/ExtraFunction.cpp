#include "ExtraFunction.h"
#include <ctime>
#include <iomanip>
#include <sstream>
std::string EF::getDateTime()
{
    // Get current time
    std::time_t now = std::time(nullptr);

    // Convert to local time
    std::tm localTime;
    localtime_s(&localTime, &now);

    // Format the date
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << localTime.tm_mday << "/"
        << std::setw(2) << (localTime.tm_mon + 1) << "/" << (localTime.tm_year + 1900);

    return ss.str();
}
