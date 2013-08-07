#include "stdio.h"
#include "time.h"

#include "util.h"

void date_string(char* string_loc)
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(string_loc,11,"%m-%d-%Y",timeinfo);
}
