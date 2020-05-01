#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
	Status(*tests[])(char*, int) =
		{
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test03_test_push_back_function,
		test04_test_size_function,
		test05_test_capacity_function,
		test06_test_concat_function_size,

		test07_test_index_too_low,
		test08_test_index_too_high,

		test09_test_resize_function,
		test10_test_c_str_function,

		test11_test_string_empty_true,
		test12_test_string_empty_false,

		test13_test_compare_strings_equal_length_case1,
		test14_test_compare_strings_equal_length_case2,
		test15_test_compare_strings_equal_length_case3,
		test16_test_compare_strings_equal_length_case4,

		test17_test_compare_strings_unequal_length_case1,
		test18_test_compare_strings_unequal_length_case2,
		test19_test_compare_strings_unequal_length_case3,
		test20_test_compare_strings_unequal_length_case4,

		test21_test_extraction_function_no_leading_whitespace,
		test22_test_extraction_function_with_leading_whitespace,
		test23_test_insertion_function,
		
		test24_test_pop_back_function_success,
		test25_test_concat_function_works
		};
	int number_of_functions = sizeof(tests) /sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;

	for(i = 0; i < number_of_functions; i++)
	{
		if(tests[i](buffer, 500) == FAILURE)
		{
			printf("FAILED: Test %d\n", i+1);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else
		{
			//printf("PASS: Test %d passed\n", i);
			//printf("\t%s\n", buffer);
			success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count,
		number_of_functions, failure_count, number_of_functions);
	return 0;

}
		
