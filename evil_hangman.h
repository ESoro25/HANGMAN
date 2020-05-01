#ifndef EVIL_HANGMAN_H
#define EVIL_HANGMAN_H

#include "associative_array.h"

void welcome(void);

Boolean askRunningTotal(void);

int verifyLength(void);

int verifyNumGuesses(void);

char verifyGuess(char history[]);

void runningWordsRemaining(int sneaky);

void congratulate(void);

void fail(void);

Boolean playAgain(void);

void clear_keyboard_buffer(void);

#endif
