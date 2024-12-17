#include "helpers.h"

const char *getCurrentDate()
{
    static char currentDate[11];

    time_t now = time(0);
    tm *localTime = localtime(&now);

    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", localTime);

    return currentDate;
}
