#include "monty.h"

/**
 * monty_nodestack - Sets the stack to stack mode.
 * @front: Stack front (not used)
 * @numP: Line number (not used)
 * Return: No return
 */
void monty_nodestack(stack_t **front, unsigned int numP)
{
	(void)front;
	(void)numP;
	custom_struct.stack_queue_flag = 0;
}



/**
 * monty_nodequeue - Sets the stack to queue mode.
 * @front: Stack front (not used)
 * @numP: Line number (not used)
 * Return: No return
 */
void monty_nodequeue(stack_t **front, unsigned int numP)
{
	(void)front;
	(void)numP;
	custom_struct.stack_queue_flag = 1;
}

/**
 * add_Queue - Adds a node to the tail of the stack (queue mode).
 * @n: New value
 * @front: Front of the stack
 * Return: No return
 */
void add_Queue(stack_t **front, int n)
{
	stack_t *_newNode, *_get_n;

	_get_n = *front;
	_newNode = malloc(sizeof(stack_t));

	if (_newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	_newNode->n = n;
	_newNode->next = NULL;

	if (_get_n)
	{
		while (_get_n->next)
		{
			_get_n = _get_n->next;
		}
	}

	if (!_get_n)
	{
		*front = _newNode;
		_newNode->prev = NULL;
	}
	else
	{
		_get_n->next = _newNode;
		_newNode->prev = _get_n;
	}
}


/**
 * monty_nodeswap - Swaps the top two elements of the stack.
 * @front: Stack front
 * @numP: Line number
 * Return: No return
 */
void monty_nodeswap(stack_t **front, unsigned int numP)
{
	stack_t *n_clone;
	int length = 0, _get_n;

	for (n_clone = *front; n_clone != NULL; n_clone = n_clone->next)
	{
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", numP);
		fclose(custom_struct.file_ptr);
		free(custom_struct.line_cont);
		freeStacks(*front);
		exit(EXIT_FAILURE);
	}

	n_clone = *front;
	_get_n = n_clone->n;
	n_clone->n = n_clone->next->n;
	n_clone->next->n = _get_n;
}


/**
 * freeStacks - Frees a doubly linked list
 * @front: Front of the stack
 */
void freeStacks(stack_t *front)
{
	stack_t *_get_n;

	for (_get_n = front; front != NULL; front = _get_n)
	{
		_get_n = front->next;
		free(front);
	}
}
