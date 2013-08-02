#include "stdio.h"
#include "time.h"

#include "util.h"

char * date_string()
{
    char date_string[50] = {0};
    time_t current_time;
    struct tm sys_time = {0};
    //sys_time.tm_year=112; // = year 2012
    //sys_time.tm_mon=9;    // = 10th month
    //sys_time.tm_mday=9;   // = 9th day
    //sys_time.tm_hour=8;   // = 8 hours
    //sys_time.tm_min=10;   // = 10 minutes
    //sys_time.tm_sec=20;   // = 20 secs
    current_time = time(NULL);
    strftime(date_string,50,"%Y-%m-%d",&current_time);
    printf("%s \n",date_string);
    return date_string;
}
