/*! 
 * \mainpage Utility for managing VIF backup files
 *
 * This utility is meant to automate the process of moving backups created by VIF 
 * from the VIF server to our backup server, name the files with the correct current 
 * date, and delete old backup files that are no longer needed.
 *  
 *  @file   main.c
 *  @brief  Main entry point for VIF Backup Manager.
 *
 */
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "util.h"

int main()
{
    CU_pSuite pSuite = NULL;
    void testReality()
    {
        CU_ASSERT(0 == 0);
    }
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    pSuite = CU_add_suite("Suite_1",NULL,NULL); //Create test suite
    CU_add_test(pSuite, "test of reality", testReality); //Add test
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
/*! This function takes nothing and returns nothing.
 *  @param [in] stuff A stuff container for stuff.
 */ 
int foo_bar(int stuff)
{
    void foo;
}
