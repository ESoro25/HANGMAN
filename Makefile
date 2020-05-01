CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o associative_array.o evil_hangman.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

unit_test: my_string.o unit_test.o test_def.o
	$(CC) -o unit_test unit_test.o test_def.o my_string.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

unit_test.o: unit_test.c unit_test.h my_string.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

test_defs.o: test_defs.c unit_test.h my_string.h
	$(CC) $(CFLAGS) -c test_defs.c -o test_defs.o

generic_vector.o: generic_vector.h my_string.h generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

associative_array.o: my_string.h generic_vector.h associative_array.h my_string.c generic_vector.c associative_array.c
	$(CC) $(CFLAGS) -c associative_array.c -o associative_array.o

evil_hangman.o: my_string.h associative_array.h generic_vector.h evil_hangman.h my_string.c associative_array.c generic_vector.c  evil_hangman.c 
	$(CC) $(CFLAGS) -c evil_hangman.c -o evil_hangman.o
clean:
	rm string_driver $($OBJECTS)
	rm unit_test
