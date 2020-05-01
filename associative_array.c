#include "associative_array.h"
#include <stdlib.h>

Node* createNode(MY_STRING key, MY_STRING value)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->key = NULL;
	my_string_assignment(&node->key, key);

	node->value = generic_vector_init_default(my_string_assignment, my_string_destroy);
	generic_vector_push_back(node->value, value);

	node->leftChild = NULL;
	node->rightChild = NULL;
	node->height = 1;
	
	return(node);
}
	
Node* insertNode(Node* node, MY_STRING key, MY_STRING value)
{
	if(node == NULL) return(createNode(key, value));

	if(my_string_compare(key, node->key) < 0)
	{
		node->leftChild = insertNode(node->leftChild, key, value);
	}
	else if(my_string_compare(key, node->key) > 0) 
	{
		node->rightChild = insertNode(node->rightChild, key, value);
	}
	else generic_vector_push_back(node->value, value);
	
/*	node->height = findMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

	int balanceFactor = getBalanceFactor(node);

	if(balanceFactor > 1 && (my_string_compare(key, node->leftChild->key) < 0)) return leftRotation(node);

	if(balanceFactor < -1 && (my_string_compare(key, node->rightChild->key) > 0))  return rightRotation(node);

	if(balanceFactor > 1 && (my_string_compare(key, node->leftChild->key) < 0))
	{
		node->rightChild = rightRotation(node->rightChild);
		return leftRotation(node);
	}

	if(balanceFactor < -1 && (my_string_compare(key, node->rightChild->key) > 0))
	{
		node->leftChild = leftRotation(node->leftChild);
		return rightRotation(node);
	}
*/	return node;
}

Node* leftRotation(Node* node)
{
	Node* yNode = node->leftChild;
	Node* yNode_Leaf = yNode->rightChild;

	yNode->rightChild = node;
	node->leftChild = yNode_Leaf;

	node->height = findMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
	yNode->height = findMax(getHeight(yNode->leftChild), getHeight(yNode->rightChild)) + 1;
	
	return yNode;
}

Node* rightRotation(Node* node)
{
	Node* xNode = node->leftChild;
	Node* xNode_Leaf = xNode->rightChild;

	xNode->rightChild = node;
	node->leftChild = xNode_Leaf;

	node->height = findMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
	xNode->height = findMax(getHeight(xNode->leftChild), getHeight(xNode->rightChild)) + 1;
	
	return xNode;
}

int getHeight(Node* node)
{
	if(node == NULL) return 0;
	
	return node->height;
}

int getBalanceFactor(Node* node)
{
	if(node == NULL) return 0;
	
	return(getHeight(node->leftChild) - getHeight(node->rightChild));
}

int findMax(int x, int y)
{
	return (x > y) ? x : y;
}

int* printInorder(Node* rootNode, int* running)
{

	if(rootNode != NULL)
	{
		printInorder(rootNode->leftChild, running);

		*running += generic_vector_get_size(rootNode->value);
	
		my_string_insertion(rootNode->key, stdout);	printf( " %d\n", generic_vector_get_size(rootNode->value));

		printInorder(rootNode->rightChild, running);
	}
	return running;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
	if(new_key == NULL) return FAILURE;

	my_string_assignment(&new_key, current_word_family);

	if(new_key == NULL) return FAILURE;

	for(int i = 0; i < my_string_get_size(word); i++)
	{
		if(guess == *my_string_at(word, i))
		{
			*my_string_at(new_key, i) = guess;
		}
	}
	return SUCCESS;
}


void destroyNodes(Node* rootNode)
{
	if(rootNode != NULL)
	{
		generic_vector_destroy(rootNode->value);
		my_string_destroy(rootNode->key);

		destroyNodes(rootNode->leftChild);
		destroyNodes(rootNode->rightChild);
	
		free(rootNode);
	}
}
/*
GENERIC_VECTOR get_largest_vector(Node* node)
{
	if(node != NULL)
	{
		int largestRoot = generic_vector_get_size(node->value);

		get_largest_vector(node->leftChild);

		int largestLeft = generic_vector_get_size(node->value);

		get_largest_vector(node->rightChild);

		int largestRight = generic_vector_get_size(node->value);
	}

	if(largestRoot > largestLeft)
		if(largestRoot > largestRight) return node->value;
			else return node->rightChild->value;
		
	else
		if(largestLeft > largestRight) return node->leftChild->value;
			else return node->rightChild->value;
}
*/
