#include "monty.h"
/**
 * addnode - add node to the front stack
 * @front: front of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **front, int n)
{

	stack_t *new_node, *aux;

	aux = *front;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *front;
	new_node->prev = NULL;
	*front = new_node;
}
