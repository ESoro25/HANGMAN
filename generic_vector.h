#ifndef INT_VECTOR
#define INT_VECTOR
#include "my_string.h"

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(Item*, Item), void (*item_destroy)(Item*));

Status generic_vector_push_back(GENERIC_VECTOR hMy_vector, Item item);

Status generic_vector_pop_back(GENERIC_VECTOR hMy_vector);

int generic_vector_get_size(GENERIC_VECTOR hMy_vector);

int generic_vector_get_capacity(GENERIC_VECTOR hMy_vector);

Boolean generic_vector_empty(GENERIC_VECTOR hMy_vector);

Item generic_vector_at(GENERIC_VECTOR hMy_vector, unsigned int index);

void generic_vector_destroy(GENERIC_VECTOR* phMy_vector);

Status generic_vector_assignment(Item* pLeft, Item Right);

#endif
