#include <stdio.h>
#include <stdlib.h>

#include "generic_vector.h"

struct vector
{
	Status (*item_assignment)(Item*, Item);
	void (*item_destroy)(Item*);
	int size;
	int capacity;
	Item* data;
};

typedef struct vector Vector;

GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(Item*, Item), void(*item_destroy)(Item*))
{
	Vector* pMy_vector = (Vector*)malloc(sizeof(Vector));
	
	if(pMy_vector != NULL)
	{
		pMy_vector->item_assignment = item_assignment;
		pMy_vector->item_destroy = item_destroy;
		pMy_vector->size = 0;
		pMy_vector->capacity = 1;
		pMy_vector->data = (Item*)calloc(sizeof(Item), pMy_vector->capacity);
		
		if(pMy_vector->data == NULL)
		{
			free(pMy_vector);
			return NULL;
		}
	}
	return (GENERIC_VECTOR)pMy_vector;
}

Status generic_vector_push_back(GENERIC_VECTOR hMy_vector, Item item)
{
	Vector* pMy_vector = (Vector*)hMy_vector;
	Item* bigArray;
	Status status;
	int i;

	if(pMy_vector->size >= pMy_vector->capacity)
	{
		bigArray = (Item*)calloc(sizeof(Item), pMy_vector->capacity * 2);
		if(bigArray == NULL) return FAILURE;

		for(i = 0; i < pMy_vector->size; i++)
		{
			bigArray[i] = pMy_vector->data[i];
		}

		for(; i < pMy_vector->capacity; i++)
		{
			bigArray[i] = NULL;
		}

		free(pMy_vector->data);
		pMy_vector->data = bigArray;
		pMy_vector->capacity *= 2;
	}

	status = pMy_vector->item_assignment(&(pMy_vector->data[pMy_vector->size]), item);
	if(status == FAILURE) return FAILURE;

	pMy_vector->size++;
	return SUCCESS;
}
	
Status generic_vector_pop_back(GENERIC_VECTOR hMy_vector)
{
	Vector* pMy_vector = (Vector*)hMy_vector;

	if(pMy_vector->size == 0) return FAILURE;

	pMy_vector->item_destroy(&(pMy_vector->data[pMy_vector->size - 1]));
	pMy_vector->size--;

	return SUCCESS;
}

int generic_vector_get_size(GENERIC_VECTOR hMy_vector)
{
	Vector* pMy_vector = (Vector*)hMy_vector;

	return pMy_vector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hMy_vector)
{
	Vector* pMy_vector = (Vector*)hMy_vector;

	return pMy_vector->capacity;
}

Boolean generic_vector_empty(GENERIC_VECTOR hMy_vector)
{
	Vector* pMy_vector = (Vector*)hMy_vector;
	
	return (Boolean)(pMy_vector->size == 0);
}

Item generic_vector_at(GENERIC_VECTOR hMy_vector, unsigned int index)
{
	Vector* pMy_vector = (Vector*)hMy_vector;

	if(index >= pMy_vector->size) return NULL;

	return(pMy_vector->data[index]);
}

void generic_vector_destroy(GENERIC_VECTOR* phMy_vector)
{
	Vector* pMy_vector = (Vector*)*phMy_vector;

	for(int i = 0; i < pMy_vector->size; i++)
	{
		pMy_vector->item_destroy(&(pMy_vector->data[i]));
	}

	free(pMy_vector->data);
	free(pMy_vector);
	*phMy_vector = NULL;
}

Status generic_vector_assignment(Item* pLeft, Item Right)
{
	Vector* leftVector = (Vector*)*pLeft;
	Vector* rightVector = (Vector*)Right;

	if(leftVector == NULL)
	{
		leftVector = generic_vector_init_default(my_string_assignment, my_string_destroy);

		if(leftVector == NULL) return FAILURE;

		*pLeft = leftVector;	
	}

	for(int i = 0; i < rightVector->size; i++)
	{
		generic_vector_push_back(leftVector, rightVector->data[i]);
	}

	return SUCCESS;
}

