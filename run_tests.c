/*!
 *  @file   run_tests.c
 *  @brief  Unit tests for VIF Backup Manager.
 */
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"

#include "util.h"

/*! Tests date_string() by basicly doing exactly what date_string() does
 *  and then testing that the result matches the value returned from 
 *  date_string(). This probobly seems redundant, but the main thing this
 *  test is doing is verifying that the interface of this fuction hasn't
 *  changed.
 */ 
void test_date_string()
{
    time_t rawtime;
    struct tm * timeinfo;
    char test_string [11];
    char new_string [11];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(test_string,11,"%m-%d-%Y",timeinfo);

    date_string(new_string);
    CU_ASSERT_STRING_EQUAL(new_string,test_string);
}

/*! Tests copy_backup_file() by attempting to access the test file that
 *  was copied by the fuction during the test call. Uses the POSIX access()
 *  fuction to do that. the F_OK parameter on the call to access() checks
 *  for existence of the file.
 */ 
void test_copy_backup_file()
{
    copy_backup_file("test_file","/tmp/test_file");
    int access_result = access("/tmp/test_file", F_OK);
    CU_ASSERT(access_result == 0);
}

/*! Sets up and runs the tests. For every new function added to the 
 *  program, there should be a test added here.  
 */
int main()
{
    /* The test suite. */  
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry. */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Create test suite. */
    pSuite = CU_add_suite("Suite_1",NULL,NULL);

    /* Add tests. */
    CU_add_test(pSuite, "test date_string()", test_date_string);
    CU_add_test(pSuite, "test copy_backup_file()", test_copy_backup_file);

    /* Run tests.*/
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
