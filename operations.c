#include "monty.h"

/**
 * monty_nodepop - prints the top
 * @front: stack front
 * @numP: line_number
 * Return: no return
*/
void monty_nodepop(stack_t **front, unsigned int numP)
{
	stack_t *n_clone;

	if (*front == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}
	n_clone = *front;
	*front = n_clone->next;
	free(n_clone);
}


/**
 * monty_nodepint - Prints the top element of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodepint(stack_t **front, unsigned int numP)
{
	if (*front == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*front)->n);
}


/**
 * monty_nodepall - Prints the stack.
 * @front: Stack front
 * @numP: Not used
 * Return: No return
 */
void monty_nodepall(stack_t **front, unsigned int numP)
{
	stack_t *n_clone = *front;
	(void)numP;

	if (n_clone == NULL)
		return;

	for (; n_clone != NULL; n_clone = n_clone->next)
	{
		printf("%d\n", n_clone->n);
	}
}


/**
 * monty_nodepush - add node to the stack
 * @front: stack front
 * @numP: line_number
 * Return: no return
*/
void monty_nodepush(stack_t **front, unsigned int numP)
{
	int k = 0, n, s_q_flag = 0;

	if (custom_struct.argument)
	{
	if (custom_struct.argument[0] == '-')
		k++;
	for (; custom_struct.argument[k] != '\0'; k++)
	{
		if (custom_struct.argument[k] > 57 || custom_struct.argument[k] < 48)
			s_q_flag = 1; }
	if (s_q_flag == 1)
	{ fprintf(stderr, "L%d: usage: push integer\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE); }
	n = atoi(custom_struct.argument);
	if (custom_struct.stack_queue_flag == 0)
		add_Node(front, n);
	else
		add_Queue(front, n);
}
