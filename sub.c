#include "monty.h"
/**
  *f_sub- sustration
  *@front: stack front
  *@num_popped: line_number
  *Return: no return
 */
void f_sub(stack_t **front, unsigned int num_popped)
{
	stack_t *aux;
	int sus, nodes;

	aux = *front;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_popped);
		fclose(custom_struct.file_pointer);
		free(custom_struct.line_content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	aux = *front;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*front = aux->next;
	free(aux);
}
