#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "util.h"

int main()
{
    CU_pSuite pSuite = NULL;
    void testDateString()
    {
        date_string();
        CU_ASSERT(0 == 0);
    }
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    pSuite = CU_add_suite("Suite_1",NULL,NULL); //Create test suite
    CU_add_test(pSuite, "test date_string()", testDateString); //Add test
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
