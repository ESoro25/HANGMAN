#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	hString = my_string_init_default();

	if(hString == NULL)
	{
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
				"my_string_init_default returns NULL", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
		}
	}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString) != 0)
	{
		status = FAILURE;
		printf("Expected a size of 0 but get %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_retrusn_0\n"
			"Did not receive 0 from get_size after init_default\n", length);
	}
	else 
	{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				, length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test03_test_push_back_function(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("Patriot");
	MY_STRING hString2 = my_string_init_c_string("Patriots");
	Status status;

	my_string_push_back(hString1, 's');

	if(my_string_compare(hString1, hString2) != 0)
	{
		status = FAILURE;
		printf("Expected string %s, got string %s\n", my_string_c_str(hString2), my_string_c_str(hString1));
		strncpy(buffer, "test03_test_push_back_function", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test03_test_push_back_function", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}
	
Status test04_test_size_function(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_get_size(hString) != 8)
	{
		status = FAILURE;
		printf("Expected size 8, got size %d\n", my_string_get_size(hString));
		strncpy(buffer, "test04_test_size_function", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test04_test_size_function", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test05_test_capacity_function(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_get_size(hString) < 8)
	{
		status = FAILURE;
		printf("Expected capacity >= 8, got capacity %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test05_test_capcity_function", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test05_test_capcity_function", length);
	}

	my_string_destroy(&hString);
	return status;
}
	
Status test06_test_concat_function_size(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("Patriots");
	MY_STRING hString2 = my_string_init_c_string("Bruins");
	Status status;

	my_string_concat(hString1, hString2);

	if(my_string_get_size(hString1) != 14)
	{
		status = FAILURE;
		printf("Expected concat size 14, got concat size, %d\n", my_string_get_size(hString1));
		strncpy(buffer, "test06_test_concat_function_size", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test06_test_concat_function_size", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test07_test_index_too_low(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_at(hString, -10) != NULL)
	{
		status = FAILURE;
		printf("Index too low, should not return anything.\n");
		strncpy(buffer, "test07_test_index_too_low", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test07_test_index_too_low", length);
	}

	my_string_destroy(&hString);
	return status;
}
	
Status test08_test_index_too_high(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_at(hString, 50) != NULL)
	{
		status = FAILURE;
		printf("Index too high, should not return anything.\n");
		strncpy(buffer, "test08_test_index_too_high", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test08_test_index_too_high", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test09_test_resize_function(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_get_capacity(hString) < 8)
	{
		status = FAILURE;
		printf("Expected capacity > 8, got capacity %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test09_test_resize_function", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test09_test_resize_function", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

Status test10_test_c_str_function(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_at(hString, my_string_get_capacity(hString)))
	{
		status = FAILURE;
		printf("Expected '\\0', got %s\n", my_string_at(hString, my_string_get_capacity(hString)));
		strncpy(buffer, "test10_test_c_str_function", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test10_test_c_str_function", length);
	}
	
	my_string_destroy(&hString);
	return status;
}

Status test11_test_string_empty_true(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("");
	Status status;

	if(my_string_empty(hString))
	{
		status = SUCCESS;
		strncpy(buffer, "test11_test_string_empty_true", length);
	}
	
	else {
		status = FAILURE;
		printf("String empty, but returned anyway.\n");
		strncpy(buffer, "test11_test_string_empty_true", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test12_test_string_empty_false(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	if(my_string_empty(hString))
	{
		status = FAILURE;
		printf("String exists, but returned empty");
		strncpy(buffer, "test12_test_string_empty_false", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test12_test_string_empty_false", length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test13_test_compare_strings_equal_length_case1(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("a");
	MY_STRING hString2 = my_string_init_c_string("z");
	Status status;

	if(my_string_compare(hString1, hString2) != -1)
	{
		status = FAILURE;
		printf("Expected comparison value -1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test13_test_compare_strings_equal_length_case1", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test13_test_compare_strings_equal_length_case1", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test14_test_compare_strings_equal_length_case2(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("z");
	MY_STRING hString2 = my_string_init_c_string("a");
	Status status;

	if(my_string_compare(hString1, hString2) != 1)
	{
		status = FAILURE;
		printf("Expected comparison value 1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test14_test_compare_strings_equal_length_case2", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test14_test_compare_strings_equal_length_case2", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test15_test_compare_strings_equal_length_case3(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("A");
	MY_STRING hString2 = my_string_init_c_string("Z");
	Status status;

	if(my_string_compare(hString1, hString2) != -1)
	{
		status = FAILURE;
		printf("Expected comparison value -1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test15_test_compare_strings_equal_length_case3", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test15_test_compare_strings_equal_length_case3", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test16_test_compare_strings_equal_length_case4(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("Z");
	MY_STRING hString2 = my_string_init_c_string("A");
	Status status;

	if(my_string_compare(hString1, hString2) != 1)
	{
		status = FAILURE;
		printf("Expected comparison value 1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test16_test_compare_strings_equal_length_case4", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test16_test_compare_strings_equal_length_case4", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test17_test_compare_strings_unequal_length_case1(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("ant");
	MY_STRING hString2 = my_string_init_c_string("zugzwang"); //my favorite word
	Status status;

	if(my_string_compare(hString1, hString2) != -1)
	{
		status = FAILURE;
		printf("Expected comparison value -1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test17_test_compare_strings_unequal_length_case1", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test17_test_compare_strings_unequal_length_case1", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test18_test_compare_strings_unequal_length_case2(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("zugzwang");
	MY_STRING hString2 = my_string_init_c_string("ant");
	Status status;

	if(my_string_compare(hString1, hString2) != 1)
	{
		status = FAILURE;
		printf("Expected comparison value 1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test18_test_compare_strings_unequal_length_case2", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test18_test_compare_strings_unequal_length_case2", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test19_test_compare_strings_unequal_length_case3(char* buffer, int length)
//no need to test the capital versions here because the prior tests tell us they are handled fine
{
	MY_STRING hString1 = my_string_init_c_string("applesauce");
	MY_STRING hString2 = my_string_init_c_string("zulu"); 
	Status status;

	if(my_string_compare(hString1, hString2) != -1)
	{
		status = FAILURE;
		printf("Expected comparison value -1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test19_test_compare_strings_unequal_length_case3", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test19_test_compare_strings_unequal_length_case3", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}
Status test20_test_compare_strings_unequal_length_case4(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("zulu");
	MY_STRING hString2 = my_string_init_c_string("applesauce"); 
	Status status;

	if(my_string_compare(hString1, hString2) != 1)
	{
		status = FAILURE;
		printf("Expected comparison value 1, got value %d\n", my_string_compare(hString1, hString2));
		strncpy(buffer, "test20_test_compare_strings_unequal_length_case4", length);
	}
	
	else {
		status = SUCCESS;
		strncpy(buffer, "test20_test_compare_strings_unequal_length_case4", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test21_test_extraction_function_no_leading_whitespace(char* buffer, int length)
{	
	MY_STRING hString1 = my_string_init_c_string("Patriots");
	MY_STRING hString2 = my_string_init_default();
	Status status;
	FILE *fp;

	fp = fopen("simple.txt", "r");

	while(my_string_extraction(hString2, fp)) {
		my_string_extraction(hString2, fp);
	}	

	if(my_string_compare(hString1, hString2) != 0)
	{
		status = FAILURE;
		printf("Expected Patriots, but got %s\n", my_string_c_str(hString2));
		strncpy(buffer, "test21_test_extraction_function_no_leading_whitespace", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test21_test_extraction_function_no_leading_whitepace", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	fclose(fp);
	
	return status;
}

Status test22_test_extraction_function_with_leading_whitespace(char* buffer, int length)
{	
	MY_STRING hString1 = my_string_init_c_string("Patriots");
	MY_STRING hString2 = my_string_init_default();
	Status status;
	FILE *fp;

	fp = fopen("simple_spaces.txt", "r");

	while(my_string_extraction(hString2, fp)) {
		my_string_extraction(hString2, fp);
	}	

	if(my_string_compare(hString1, hString2) != 0)
	{
		status = FAILURE;
		printf("Expected Patriots, but got %s\n", my_string_c_str(hString2));
		strncpy(buffer, "test21_test_extraction_function_no_leading_whitespace", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test21_test_extraction_function_no_leading_whitepace", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	fclose(fp);
	
	return status;
}

Status test23_test_insertion_function(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Patriots");
	Status status;

	FILE* fp = fopen("empty.txt", "w");

	if(my_string_insertion(hString, fp))
	{
		status = SUCCESS;
		strncpy(buffer, "test23_test_insertion_function", length);
	}

	else {
		status = FAILURE;
		printf("Unable to insert string\n");
		strncpy(buffer, "test23_test_insertion_function", length);
	}

	my_string_destroy(&hString);
	fclose(fp);
	
	return status;
}		

Status test24_test_pop_back_function_success(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("Patriots");
	MY_STRING hString2 = my_string_init_c_string("Patriot");
	Status status;

	my_string_pop_back(hString1);
	my_string_c_str(hString1);

	if(my_string_compare(hString1, hString2) != 0)
	{
		status = FAILURE;
		printf("Expected %s, but got %s\n", my_string_c_str(hString2), my_string_c_str(hString1));
		printf("compare returns %d and strcmp returns %d\n", my_string_compare(hString1, hString2), strcmp(hString1, hString2));
		printf("Expected length %d, got length %d\n", my_string_get_size(hString2), my_string_get_size(hString1));
		strncpy(buffer, "test24_test_pop_back_function_success", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test24_test_pop_back_function_success", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test25_test_concat_function_works(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("Patriots");
	MY_STRING hString2 = my_string_init_c_string("Bruins");
	MY_STRING hString3 = my_string_init_c_string("PatriotsBruins");
	Status status;

	my_string_concat(hString1, hString2);
	my_string_c_str(hString1);
	my_string_c_str(hString3);

	if(my_string_compare(hString1, hString3) != 0)
	{
		status = FAILURE;
		printf("compare returns %d and strcmp returns %d\n", my_string_compare(hString1, hString3), strcmp(hString1, hString3));
		printf("Expected length %d, got length %d\n", my_string_get_size(hString3), my_string_get_size(hString1));
		printf("Expected string %s, but got %s\n", my_string_c_str(hString3), my_string_c_str(hString1));
		strncpy(buffer, "test25_test_concat_function_works", length);
	}

	else {
		status = SUCCESS;
		strncpy(buffer, "test25_test_concat_function_works", length);
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	my_string_destroy(&hString3);
	return status;
}
