#include "header.h"

HASH* Build_Hash_For_Test ()
{
  HASH* hash = HASH_Create ();

  HASH_Insert (hash, 10, 100);
  HASH_Insert (hash, 'B', 150);
  HASH_Insert (hash, 9, 9);
  HASH_Insert (hash, 'F', 200);

  return hash;

}

void Test_Hash_Size ()
{
  HASH *hash = Build_Hash_For_Test();
  CU_ASSERT_EQUAL (HASH_Get_Size (hash), MAX_HASH_SIZE);
  return;
}

void Test_Hash_Elements ()
{
  HASH *hash = Build_Hash_For_Test();

  CU_ASSERT_EQUAL (HASH_Get_hash_element(hash, 100), 10);
  CU_ASSERT_EQUAL (HASH_Get_hash_element(hash, 150), 'B');
  CU_ASSERT_EQUAL (HASH_Get_hash_element(hash, 9), 9);
  CU_ASSERT_EQUAL (HASH_Get_hash_element(hash, 200), 'F');
  return;
}

int main ()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry ())
      return CU_get_error ();
  
    CU_pSuite hash_test_size = NULL;
    CU_pSuite hash_test_elements = NULL;
  
    // Add a suite to the registry
    hash_test_size = CU_add_suite ("Testing hash size", 0, 0);
    hash_test_elements = CU_add_suite ("Testing hash elements", 0, 0);
    CU_add_test (hash_test_size, "Testing hash size", Test_Hash_Size);
    CU_add_test (hash_test_elements, "Testing hash elements", Test_Hash_Elements);
    
    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();

    return CU_get_error();
   	return 0;
}