#include "monty.h"

/**
 *monty_noderotr- rotates the stack to the bottom
 *@front: stack front
 *@numP: line_number
 *Return: no return
 */
void monty_noderotr(stack_t **front, unsigned int numP)
{
	stack_t *clone;

	clone = *front;
	(void)numP;
	if (*front == NULL || (*front)->next == NULL)
	{
		return;
	}
	while (clone->next)
	{
		clone = clone->next;
	}
	clone->next = *front;
	clone->prev->next = NULL;
	clone->prev = NULL;
	(*front)->prev = clone;
	(*front) = clone;
}
