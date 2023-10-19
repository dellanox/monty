#include "monty.h"
/**
 * f_queue - prints the top
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_queue(stack_t **front, unsigned int num_popped)
{
	(void)front;
	(void)num_popped;
	custom_struct.stack_queue_flag = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @front: front of the stack
 * Return: no return
*/
void addqueue(stack_t **front, int n)
{
	stack_t *new_node, *aux;

	aux = *front;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*front = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
