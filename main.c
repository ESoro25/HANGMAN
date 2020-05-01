#include <stdio.h>
#include <stdbool.h>
#include "evil_hangman.h"

int main(int argc, char* argv[]) {
	
	GENERIC_VECTOR vector_of_strings[30];
	MY_STRING holdWord = my_string_init_default();
	FILE* dictionary = fopen("dictionary.txt", "r");
	
	MY_STRING wordFamily = my_string_init_default();
	MY_STRING newKey = my_string_init_default();

	Node* node = NULL;
	char history[26];
	
	int zero = 0;

	for(int i = 0; i < 30; i++)
	{
		vector_of_strings[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
	}

	while(my_string_extraction(holdWord, dictionary) == SUCCESS)
	{
		int size = my_string_get_size(holdWord);
		generic_vector_push_back(vector_of_strings[size], holdWord);
	}
	
	welcome();

	bool running = askRunningTotal();
	int length = verifyLength();

/*	int numGuesses = verifyNumGuesses();

	while(numGuesses > 0)
	{

*/		char guess = verifyGuess(history);
		int numGuessCalls = 0;

		history[numGuessCalls] = guess;
		numGuessCalls++;	

		generateWordFamily(wordFamily, length);

		GENERIC_VECTOR working_words = NULL;

		generic_vector_assignment(&working_words, vector_of_strings[length]);	

			for(int i = 0; i < generic_vector_get_size(working_words); i++)
			{
				get_word_key_value(wordFamily, newKey, generic_vector_at(working_words, i), guess); 
				
				node = insertNode(node, newKey, generic_vector_at(working_words, i));
			}

		int val = *printInorder(node, &zero);
		if(!running) runningWordsRemaining(val);

		
		my_string_destroy(&wordFamily);
		my_string_destroy(&newKey);
		my_string_destroy(&holdWord);

		for(int i = 0; i < 30; i++)
		{
			generic_vector_destroy(&vector_of_strings[i]);
		}
//	}
	return 0;
}


