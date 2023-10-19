#include "monty.h"
/**
 * f_push - add node to the stack
 * @front: stack front
 * @num_popped: line_number
 * Return: no return
*/
void f_push(stack_t **front, unsigned int num_popped)
{
	int n, j = 0, flag = 0;

	if (custom_struct.argument)
	{
		if (custom_struct.argument[0] == '-')
			j++;
		for (; custom_struct.argument[j] != '\0'; j++)
		{
			if (custom_struct.argument[j] > 57 || custom_struct.argument[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num_popped);
			fclose(custom_struct.file_pointer);
			free(custom_struct.line_content);
			free_stack(*front);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE); }
	n = atoi(custom_struct.argument);
	if (custom_struct.stack_queue_flag == 0)
		addnode(front, n);
	else
		addqueue(front, n);
}
