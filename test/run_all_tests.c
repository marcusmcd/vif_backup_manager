/*!
 *  @file   run_all_tests.c
 *  @brief  Unit tests for VIF Backup Manager.
 */
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include "../src/util.h"

/*! Tests date_string() by basicly doing exactly what date_string() does
 *  and then testing that the result matches the value returned from 
 *  date_string(). This probobly seems redundant, but the main thing this
 *  test is doing is verifying that the interface of this fuction hasn't
 *  changed.
 */ 
START_TEST(test_date_string)
{
    time_t rawtime;
    struct tm * timeinfo;
    char test_string [11];
    char new_string [11];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(test_string,11,"%m-%d-%Y",timeinfo);

    date_string(new_string);
    ck_assert_str_eq(new_string,test_string);
}
END_TEST

/*! Tests copy_backup_file() by attempting to access the test file that
 *  was copied by the fuction during the test call. Uses the POSIX access()
 *  fuction to do that. the F_OK parameter on the call to access() checks
 *  for existence of the file.
 */ 
START_TEST(test_copy_backup_file)
{
    /* Setup */
    open("test_file", O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
    mkdir("tmp", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    /* Test */
    copy_backup_file("test_file","./tmp/test_file");
    int access_result = access("./tmp/test_file", F_OK);
    ck_assert_int_eq(access_result,0);
    /* Teardown */
    remove("test_file");
    remove("./tmp/test_file");
    remove("tmp");
}
END_TEST

Suite *test_suite (void)
{
    Suite *s = suite_create("test");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_date_string);
    tcase_add_test(tc_core, test_copy_backup_file);

    suite_add_tcase (s, tc_core);
    return s;
}

int main (void)
{
    int number_failed;
    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
