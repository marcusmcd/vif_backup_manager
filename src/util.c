/*!
 *  @file   util.c
 *  @brief  Utility functions for VIF Backup Manager.
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "util.h"

/*! Takes a pointer to a string and writes the current date into that string. 
 *  The date created should be of the format MM-DD-YYYY.
 *
 *  @param [in] string_loc A Pointer to a string that will have the date written into it.
 */ 
void date_string(char* string_loc)
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(string_loc,11,"%m-%d-%Y",timeinfo);
}

void copy_backup_file(char* source_file_path,char* dest_file_path)
{
    pid_t pid;
    pid = fork();
    if (pid == 0) 
    {
        
    }
    else if (pid < 0) 
    {
        
    }
    else 
    {
        
    }
}