#include "monty.h"
/**
 * f_pop - prints the top
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_pop(stack_t **front, unsigned int num_popped)
{
	stack_t *n_clone;

	if (*front == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	n_clone = *front;
	*front = n_clone->next;
	free(n_clone);
}
