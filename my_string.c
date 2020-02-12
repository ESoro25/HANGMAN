#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

typedef struct my_string {

	int capacity;
	int size;
	char* data;

} My_String;

MY_STRING my_string_init_default(void) {

	My_String* string;
	string = (My_String*)malloc(sizeof(My_String));

	if(string != NULL){
		string->capacity = 7;
		string->size = 0;
		string->data = (char*)malloc(sizeof(char) * string->capacity);

		return string;
	}
	else return NULL;
}

void my_string_destroy(MY_STRING* phMy_string) {
	
	free(((My_String*)(*phMy_string))->data);
	free(*phMy_string);

	*phMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string) {
	
	My_String* string;
	string = (My_String*)malloc(sizeof(My_String));

	int capacity = 0;
	int size = 0;

	for(int i = 0; c_string[i] != '\0'; i++)
	{
		capacity++;
		size++;
	}

	capacity++;

	string->capacity = capacity;
	string->size = size;

	string->data = (char*)malloc(sizeof(char) * string->capacity);

	for(int i = 0; c_string[i] != '\0'; i++)
	{
		string->data[i] = c_string[i];
	}
	
	
	if(string != NULL) {
		return string;
		}
	else return NULL;

}

int my_string_get_capacity(MY_STRING hMy_string) {

	My_String *pMy_string = (My_String*)(hMy_string);
	
	return pMy_string->capacity;

}

int my_string_get_size(MY_STRING hMy_string) {

	My_String *pMy_string = (My_String*)(hMy_string);
	
	return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {

	My_String *Left_String = (My_String*)(hLeft_string);
	My_String *Right_String = (My_String*)(hRight_string);

	int value = strcmp(Left_String->data, Right_String->data);

	if(value > 0) return 1;
		else if(value < 0) return -1;
		else return 0;	
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {

	My_String *pMy_string = (My_String*)(hMy_string);

	if(fp == NULL) return FAILURE;

	char holder;

	while(fscanf(fp, "%c", &holder) == 1) {
		if(fscanf(fp, " ") == 1) {
		       ungetc(fp, ' ');
	       	       return SUCCESS;
	 	}		

		if(pMy_string->size == pMy_string->capacity) {
			char* bigString = (char*)malloc(sizeof(char) * (pMy_string->capacity * 2));
			if(bigString == NULL) return FAILURE;
		}

		for(int i = 0; i < pMy_string->size; i++) {
			bigString[i] = pMy_string->data[i];
		}
	
	
		free(pMy_string->data);
		pMy_string->data = bigString;
		pMy_string->capacity *= 2;

	}
	pMy_string->data[pMy_string->size] = holder;
	pMy_string->size += 1;	


	
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {


}

Status my_string_push_back(MY_STRING hMy_string, char item) {

	char item;

	while(fscanf(fp, "%c", &item) == 1) {
		if(fscanf(fp, " ") == 1) {
			ungetc(fp, ' ');
			return SUCCESS;
		}

		if(pMy_string->size == pMy_string->capacity) {
			char* bigString = (char*)malloc(sizeof(char) * (pMy_string->capacity * 2));
			if(bigString == NULL) return FAILURE;
		}

		for(int i = 0; i < pMy_string->size; i++) {
			bigString[i] = pMy_string->data[i];
		}
	
	
		free(pMy_string->data);
		pMy_string->data = bigString;
		pMy_string->capacity *= 2;

	}
	pMy_string->data[pMy_string->size] = item;
	pMy_string->size += 1;	


}
