#include "evil_hangman.h"
#include <ctype.h>

void welcome(void)
{
	printf("\n");
	printf("-------------------------------------------------\n");
	printf("Welcome to Evil Hangman!\n");
	printf("I hope this is as hard for you as it was to make.\n");
	printf("-------------------------------------------------\n");
	printf("\n");
}

Boolean askRunningTotal(void)
{
	char running;

	printf("Do you want a running total of the number of remaining words? (y/n): ");
	scanf(" %c", &running);	

	while(running != 'y' && running != 'Y' && running != 'n' && running != 'N')
	{
		clear_keyboard_buffer();
		printf("Invalid Entry, try again: ");
		scanf(" %c", &running);
	}

	if(tolower(running) == 'y') return TRUE;
	else return FALSE;

}

int verifyLength(void)
{
	int length;

	printf("With what word length do you want to play?: ");
	int temp = scanf("%d", &length);

	while(temp != 1)
	{
			clear_keyboard_buffer();
			printf("That is not a number. Try again: ");
			temp = scanf("%d", &length);
	}

	while(length < 2 || length == 23 || length == 25 || length == 26 || length == 27 || length > 29)
		{
			clear_keyboard_buffer();
			printf("There is no word length of %d. Try again: ", length);
			scanf("%d", &length);
		}
	
	return length;
}
	

int verifyNumGuesses(void)
{
	int numGuesses;

	printf("How many guesses do you want?: ");
	int temp = scanf("%d", &numGuesses);

		while(numGuesses < 1 || temp != 1)
		{
			clear_keyboard_buffer();
			if(temp != 1) printf("That is not a number. Try again: ");
			else printf("How do you expect to play with %d guesses? Try again: ", numGuesses);
			temp = scanf("%d", &numGuesses);

		}

	return numGuesses;
}

char verifyGuess(char history[])
{
	char guess;

	printf("Enter letter to guess: ");
	scanf(" %c", &guess);

	while(isalpha(guess) == 0)
	{
		printf("You have not entered a letter. Try again: ");
		clear_keyboard_buffer();
		scanf(" %c", &guess);
	}

	for(int i = 0; i < 26; i++)
	{
		if(tolower(guess) == history[i])
		{
			printf("You have already guessed this letter. Try again: ");
			clear_keyboard_buffer();
			scanf("	%c", &guess);
		
			while(isalpha(guess) == 0)
			{
				printf("You have not entered a letter. Try again: ");
				clear_keyboard_buffer();
				scanf(" %c", &guess);
			}
		}
	}
	
	return tolower(guess);
}

void runningWordsRemaining(int sneaky)
{
	printf("Total Words Remaining: %d\n", sneaky);
}
void congratulate(void);

void fail(void);

Boolean playAgain(void)
{
	char replay;

	printf("Do you want to play again? (y/n): ");
	scanf(" %c", &replay);

		while(replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'n')
		{
			clear_keyboard_buffer();
			printf("Invalid Entry, try again: ");
			scanf(" %c", &replay);
		}

		if(tolower(replay) == 'y') return TRUE;
		else return FALSE;
}

void clear_keyboard_buffer(void)
{
	//all praise the magic function, no one knows how it works, but it does
	char c;
	scanf("%c", &c);

	while(c != '\n' && c != '\0')
	{
		scanf("%c", &c);
	}
} 

