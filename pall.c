#include "monty.h"
/**
 * f_pall - prints the stack
 * @front: stack front
 * @num_popped: no used
 * Return: no return
*/
void f_pall(stack_t **front, unsigned int num_popped)
{
	stack_t *n_clone;
	(void)num_popped;

	n_clone = *front;
	if (n_clone == NULL)
		return;
	while (n_clone)
	{
		printf("%d\n", n_clone->n);
		n_clone = n_clone->next;
	}
}
