#include <stdio.h>
#include "generic.h"

typedef void* MY_STRING;
typedef enum status{FAILURE, SUCCESS} Status;
typedef enum boolean{TRUE, FALSE} Boolean;

MY_STRING my_string_init_default(void);

void my_string_destroy(Item* pItem);

MY_STRING my_string_init_c_string(const char* c_string);

int my_string_get_capacity(MY_STRING hMy_string);

int my_string_get_size(MY_STRING hMy_string);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_push_back(MY_STRING hMy_string, char item);

Status my_string_pop_back(MY_STRING hMy_string);

char* my_string_at(MY_STRING hMy_String, int index);

char* my_string_c_str(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

Boolean my_string_empty(MY_STRING hMy_String);

Status my_string_assignment(Item* pLeft, Item Right);

Status generateWordFamily(MY_STRING hMy_String, int length);
