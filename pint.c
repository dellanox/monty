#include "monty.h"
/**
 * f_pint - prints the top
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_pint(stack_t **front, unsigned int num_popped)
{
	if (*front == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*front)->n);
}
