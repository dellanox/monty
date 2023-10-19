#include "monty.h"
/**
  *monty_noderotl- rotates the stack to the top
  *@front: stack front
  *@numP: line_number
  *Return: no return
 */
void monty_noderotl(stack_t **front, unsigned int numP)
{
	stack_t *temp = *front, *_get_n;

	(void)numP;
	if (*front == NULL || (*front)->next == NULL)
	{
		return;
	}
	_get_n = (*front)->next;
	_get_n->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *front;
	(*front)->next = NULL;
	(*front)->prev = temp;
	(*front) = _get_n;
}
