#include "monty.h"

/**
 * monty_nodeadd - Adds the top two elements of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodeadd(stack_t **front, unsigned int numP)
{
	/* Reordered the statements for readability*/
	stack_t *n_clone = *front;
	int length = 0, _get_n;

	/* Count the elements*/
	while (n_clone)
	{
		n_clone = n_clone->next;
		length++;
	}

	/* Check if the stack has at least 2 elements*/
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements*/
	n_clone = *front;
	_get_n = n_clone->n + n_clone->next->n;
	n_clone->next->n = _get_n;
	*front = n_clone->next;
	free(n_clone);
}


/**
 * monty_nodediv - Divide the top two elements of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodediv(stack_t **front, unsigned int numP)
{
	/* Reordered the statements for readability*/
	stack_t *n_clone = *front;
	int length = 0, _get_n;

	/* Count the elements*/
	while (n_clone)
	{
		n_clone = n_clone->next;
		length++;
	}

	/* Check if the stack has at least 2 elements*/
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	n_clone = *front;

	/* Check for division by zero*/
	if (n_clone->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	_get_n = n_clone->next->n / n_clone->n;
	n_clone->next->n = _get_n;
	*front = n_clone->next;
	free(n_clone);
}


/**
 * monty_nodesub - Subtracts the top element from the second top element.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodesub(stack_t **front, unsigned int numP)
{
	stack_t *_get_n;
	int subst;
	int monty_nodes = 0;

	_get_n = *front;


	/* Count the number of elements in the stack */
	while (_get_n != NULL)
	{
		monty_nodes++;
		_get_n = _get_n->next;
	}

	if (monty_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	_get_n = *front;
	subst = _get_n->next->n - _get_n->n;
	_get_n->next->n = subst;
	*front = _get_n->next;
	free(_get_n);
}


/**
 * monty_nodemul - Multiplies the top two elements of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodemul(stack_t **front, unsigned int numP)
{
	/* Initialize variables */
	stack_t *n_clone = *front;
	int length = 0;
	int _get_n;

	/* Calculate the length of the stack */
	for (; n_clone != NULL; n_clone = n_clone->next)
	{
		length++;
	}

	/* Check if the stack has at least two elements */
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	/* Retrieve the top two elements, multiply, and update the stack */
	n_clone = *front;
	_get_n = n_clone->next->n * n_clone->n;
	n_clone->next->n = _get_n;
	*front = n_clone->next;
	free(n_clone);
}

