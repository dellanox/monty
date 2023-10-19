#include "monty.h"

/**
 * add_Node - Add a node to the front of the stack.
 * @front: Front of the stack
 * @n: New value
 * Return: No return
 */
void add_Node(stack_t **front, int n)
{
	/* Reordered the statements for better readability*/
	stack_t *_newNode, *_get_n;

	_newNode = malloc(sizeof(stack_t));
	if (_newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	_get_n = *front;
	if (_get_n)
	{
		_get_n->prev = _newNode;
	}

	_newNode->n = n;
	_newNode->next = *front;
	_newNode->prev = NULL;

	*front = _newNode;
}
