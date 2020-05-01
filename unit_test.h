#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
#include <stdio.h>
#include <string.h>


Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test03_test_push_back_function(char* buffer, int length);
Status test04_test_size_function(char* buffer, int length);
Status test05_test_capacity_function(char* buffer, int length);
Status test06_test_concat_function_size(char* buffer, int length);

Status test07_test_index_too_low(char* buffer, int length);
Status test08_test_index_too_high(char* buffer, int length);

Status test09_test_resize_function(char* buffer, int length);
Status test10_test_c_str_function(char* buffer, int length);

Status test11_test_string_empty_true(char* buffer, int length);
Status test12_test_string_empty_false(char* buffer, int length);

Status test13_test_compare_strings_equal_length_case1(char* buffer, int length);
Status test14_test_compare_strings_equal_length_case2(char* buffer, int length);
Status test15_test_compare_strings_equal_length_case3(char* buffer, int length);
Status test16_test_compare_strings_equal_length_case4(char* buffer, int length);

Status test17_test_compare_strings_unequal_length_case1(char* buffer, int length);
Status test18_test_compare_strings_unequal_length_case2(char* buffer, int length);
Status test19_test_compare_strings_unequal_length_case3(char* buffer, int length);
Status test20_test_compare_strings_unequal_length_case4(char* buffer, int length);

Status test21_test_extraction_function_no_leading_whitespace(char* buffer, int length);
Status test22_test_extraction_function_with_leading_whitespace(char* buffer, int length);
Status test23_test_insertion_function(char* buffer, int length);

Status test24_test_pop_back_function_success(char* buffer, int length);
Status test25_test_concat_function_works(char* buffer, int length);
#endif
