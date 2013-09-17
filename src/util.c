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

/*! Takes two strings containing a source file path and a destination file
 *  path. Copies the file from the source to the destination. Designed to be
 *  called for a single file. User should have checked for existence of the
 *  file before calling this function.
 *
 *  @param [in] source_file_path A string containing a source file path.
 *  @param [in] dest_file_path A string containing a destination file path.
 */ 
void copy_backup_file(char* source_file_path,char* dest_file_path)
{
    int access_result = access(source_file_path, F_OK);
    pid_t pid;
    pid = fork();
    if (pid == 0) 
    {
        if (access_result == 0)
        {
            execl("/bin/cp", "/bin/cp", source_file_path, dest_file_path, (char *)0);
        }
        else
        {
            printf("Error: The specified file does not exist.");
        }
    }
    else if (pid < 0) 
    {
        
    }
    else 
    {
        wait();
    }
}
