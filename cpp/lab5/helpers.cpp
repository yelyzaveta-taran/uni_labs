#include "helpers.h"
#include "constants.h"
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

string getCurrentDate()
{

    time_t now = time(0);
    tm *localTime = localtime(&now);

    char currentDate[11];
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", localTime);

    return std::string(currentDate);
}
