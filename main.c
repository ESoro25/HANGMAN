#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]) {

	MY_STRING hMy_string = NULL;

	hMy_string = my_string_init_c_string("hi");

	MY_STRING hLeft_string = my_string_init_c_string("app");
	MY_STRING hRight_string = my_string_init_c_string("apple");

	printf("String Capacity: %d\n", my_string_get_capacity(hMy_string));

	printf("String Size: %d\n", my_string_get_size(hMy_string));

	printf("Lexicographical Comparison: %d\n", my_string_compare(hLeft_string, hRight_string));

	my_string_destroy(&hMy_string);
	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);

	return 0;
}
