#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @front: front of the stack
*/
void free_stack(stack_t *front)
{
	stack_t *aux;

	aux = front;
	while (front)
	{
		aux = front->next;
		free(front);
		front = aux;
	}
}
