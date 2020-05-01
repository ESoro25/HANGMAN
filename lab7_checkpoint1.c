#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

int main(int argc, char* argv[]) {
	
	GENERIC_VECTOR vector_of_strings[30];
	MY_STRING holdWord = my_string_init_default();
	FILE* dictionary = fopen("dictionary.txt", "r");

	for(int i = 0; i < 30; i++)
	{
		vector_of_strings[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
	}

	while(my_string_extraction(holdWord, dictionary) == SUCCESS)
	{
		int size = my_string_get_size(holdWord);
//		printf("SIZE - %d\n", size);
		generic_vector_push_back(vector_of_strings[size], holdWord);
	}

	fclose(dictionary);

	for(int i = 1; i < 30; i++)
	{
		printf("Number of words of length %d in the alphabet - %d\n", i , generic_vector_get_size(vector_of_strings[i]));
	}

	my_string_destroy(&holdWord);

	for(int i = 0; i < 30; i++)
	{
		generic_vector_destroy(&vector_of_strings[i]);
	}

return 0;
}

