#include "stdio.h"
#include "time.h"

#include "util.h"

char * date_string()
{
    time_t rawtime;
    struct tm * timeinfo;
    char date_string [50];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(date_string,50,"%m-%d-%Y",timeinfo);
    return date_string;
}
