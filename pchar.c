#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_pchar(stack_t **front, unsigned int num_popped)
{
	stack_t *n_clone;

	n_clone = *front;
	if (!n_clone)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	if (n_clone->n > 127 || n_clone->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n_clone->n);
}
