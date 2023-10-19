#include "monty.h"

/**
 * monty_nodemod - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodemod(stack_t **front, unsigned int numP)
{
	stack_t *n_clone;
	int length = 0, _get_n;

	for (n_clone = *front; n_clone != NULL; n_clone = n_clone->next)
	{
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	n_clone = *front;
	if (n_clone->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	_get_n = n_clone->next->n % n_clone->n;
	n_clone->next->n = _get_n;
	*front = n_clone->next;
	free(n_clone);
}


/**
  *monty_nodenop- nothing
  *@front: stack front
  *@numP: line_number
  *Return: no return
 */
void monty_nodenop(stack_t **front, unsigned int numP)
{
	(void) numP;
	(void) front;
}

/**
 * monty_nodepchar - prints the char at the top of the stack,
 * followed by a new line
 * @front: stack front
 * @numP: line_number
 * Return: no return
*/
void monty_nodepchar(stack_t **front, unsigned int numP)
{
	stack_t *n_clone;

	n_clone = *front;
	if (!n_clone)
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", numP);
	fclose(custom_struct.file_ptr);
	free(custom_struct.line_cont);
	freeStacks(*front);
	exit(EXIT_FAILURE);
	}
	if (n_clone->n > 127 || n_clone->n < 0)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", numP);
	fclose(custom_struct.file_ptr);
	free(custom_struct.line_cont);
	freeStacks(*front);
	exit(EXIT_FAILURE);
	}
	printf("%c\n", n_clone->n);
}

/**
 * monty_nodepstr - prints the string starting at the top of the stack,
 * followed by a new
 * @front: stack front
 * @numP: line_number
 * Return: no return
*/
void monty_nodepstr(stack_t **front, unsigned int numP)
{
	stack_t *n_clone;
	(void)numP;

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
