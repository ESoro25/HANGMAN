#ifndef ASSOCIATIVE_ARRAY
#define ASSOCIATIVE_ARRAY

#include "generic_vector.h"

typedef struct Node
{
	MY_STRING key;
	GENERIC_VECTOR value;

	int height;

	struct Node* leftChild;
	struct Node* rightChild;
} Node;

Node* createNode(MY_STRING key, MY_STRING  value);

Node* insertNode(Node* node, MY_STRING key, GENERIC_VECTOR value);

Node* leftRotation(Node* node);

Node* rightRotation(Node* node);

int getHeight(Node* node);

int getBalanceFactor(Node* node);

int findMax(int x, int y);

int* printInorder(Node* rootNode, int* running);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);
	
void destroyNodes(Node* rootNode);

GENERIC_VECTOR get_largest_vector(Node* node);

#endif 
