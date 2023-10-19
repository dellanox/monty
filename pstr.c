#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_pstr(stack_t **front, unsigned int num_popped)
{
	stack_t *n_clone;
	(void)num_popped;

	n_clone = *front;
	while (n_clone)
	{
		if (n_clone->n > 127 || n_clone->n <= 0)
		{
			break;
		}
		printf("%c", n_clone->n);
		n_clone = n_clone->next;
	}
	printf("\n");
}
