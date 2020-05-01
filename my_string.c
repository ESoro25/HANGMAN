#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"

typedef struct my_string {

	int capacity;
	int size;
	char* data;

} My_String;

MY_STRING my_string_init_default(void) {

	My_String* pMy_string = (My_String*)malloc(sizeof(My_String));
	if(pMy_string != NULL)
	{
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);

	if(pMy_string->data == NULL)
	{
		free(pMy_string);
		pMy_string = NULL;
		}
	}

	return pMy_string;
}

void my_string_destroy(Item* pItem) {
	
	My_String* pMy_string = (My_String*)*pItem;
	
	free(pMy_string->data);
	pMy_string->data = NULL;
	
	free(pMy_string);
	pMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string) {
	
	My_String* string;
	string = (My_String*)malloc(sizeof(My_String));

	if(string == NULL) return NULL;

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

	if(string->data == NULL) return NULL;

	for(int i = 0; c_string[i] != '\0'; i++)
	{
		string->data[i] = c_string[i];
	}
	
	return string;	
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

	if(Left_String->size < Right_String->size)
	{
		for(int i = 0; i < Left_String->size; i++)
		{
			if(Left_String->data[i] < Right_String->data[i]) return -1;
			else if(Left_String->data[i] > Right_String->data[i]) return 1;
		}
	}
	else 
	{
		for(int i = 0; i < Right_String->size; i++)
		{
			if(Left_String->data[i] < Right_String->data[i]) return -1;
			else if(Left_String->data[i] > Right_String->data[i]) return 1;
		}
	}
	return 0;

}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {

	My_String *pMy_string = (My_String*)(hMy_string);
	char letter = getc(fp);
	pMy_string->size = 0;

	if(fp == NULL) return FAILURE;

	while(isspace(letter) && letter != EOF)
	{
		letter = getc(fp);
	}

	if(letter == EOF) return FAILURE;

	my_string_push_back(pMy_string, letter);
	letter = getc(fp);

	while(!isspace(letter) && letter != EOF)
	{
		my_string_push_back(pMy_string, letter);
		letter = getc(fp);
	}

	if(letter != EOF) ungetc(letter, fp);
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {

	My_String *pMy_string = (My_String*)(hMy_string);

	if(fp == NULL) return FAILURE;

	for(int i = 0; i < pMy_string->size; i++)
	{
		fprintf(fp, "%c", pMy_string->data[i]);
	}
	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item) {

	My_String *pMy_string = (My_String*)(hMy_string);


		if(pMy_string->size >= pMy_string->capacity) {
			char* bigString = (char*)malloc(sizeof(char) * (pMy_string->capacity * 2));
			if(bigString == NULL) return FAILURE;
	
			for(int i = 0; i < pMy_string->size; i++) {
				bigString[i] = pMy_string->data[i];
			}
	
	
			free(pMy_string->data);
			pMy_string->data = bigString;
			pMy_string->capacity *= 2;

		}

	pMy_string->data[pMy_string->size] = item;
	pMy_string->size++;	

	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string) {

	My_String *pMy_string = (My_String*)(hMy_string);

	if(pMy_string->size == 0) return FAILURE;

	pMy_string->size--;

	return SUCCESS;

}

char* my_string_at(MY_STRING hMy_string, int index) {

	My_String *pMy_string = (My_String*)(hMy_string);

	if(pMy_string == NULL || index >= pMy_string->size || index < 0) return NULL;

	return &(pMy_string->data[index]);

}

char* my_string_c_str(MY_STRING hMy_string) {

	My_String *pMy_string = (My_String*)(hMy_string);

	char* bigString;

	if(pMy_string->size >= pMy_string->capacity)
	{
		bigString = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
		
		if(bigString == NULL) return NULL;

		for(int i = 0; i < pMy_string->size; i++)
		{
			bigString[i] = pMy_string->data[i];
		}

		free(pMy_string->data);
		pMy_string->data = bigString;
	}

	pMy_string->data[pMy_string->size]  = '\0';

	return pMy_string->data;

}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {

	My_String *pResult = (My_String*)(hResult);
	My_String *pAppend = (My_String*)(hAppend);

	int mergedSize = pResult->size + pAppend->size;

	pResult->data = (char*)realloc(pResult->data, sizeof(char) * mergedSize);

	if(pResult == NULL || pAppend == NULL) return FAILURE;

	for(int i = 0; i < pAppend->data[i]; i++)
	{
		my_string_push_back(pResult, pAppend->data[i]);
	}

	return SUCCESS;

}

Boolean my_string_empty(MY_STRING hMy_string) {

	My_String *pMy_string = (My_String*)(hMy_string);

	return(pMy_string->size <= 0);
}

Status  my_string_assignment(Item* pLeft, Item Right)
{
	My_String *LeftString = (My_String*)*pLeft;
	My_String *RightString = (My_String*)Right;

	if(LeftString == NULL)
	{
		LeftString = my_string_init_default();

		if(LeftString == NULL) return FAILURE;

		*pLeft = LeftString;
	}
	else  LeftString->size = 0;

	for(int i = 0; i < RightString->size; i++)
	{
		my_string_push_back(LeftString, RightString->data[i]);
	}

	return SUCCESS;
}
		
Status generateWordFamily(MY_STRING hMy_string, int length)
{
	My_String *pMy_string = (My_String*)(hMy_string);

	if(pMy_string == NULL) return FAILURE;

	for(int i = 0; i < length; i++)
	{
		my_string_push_back(pMy_string, '-');
	}
	
	return SUCCESS;
}
