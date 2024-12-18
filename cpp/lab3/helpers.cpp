#include "helpers.h"
#include <ctime>
#include <string>

std::string getCurrentDate()
{

    time_t now = time(0);
    tm *localTime = localtime(&now);

    char currentDate[11];
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", localTime);

    return std::string(currentDate);
}
