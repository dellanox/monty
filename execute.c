#include "monty.h"

/**
 * exec - Executes the opcode.
 * @line_cont: Line content
 * @stack: Front linked list - stack
 * @numP: Line counter
 * @file_ptr: Pointer to Monty file
 * Return: No return
 */
int exec(char *line_cont, stack_t **stack, unsigned int numP, FILE *file_ptr)
{
	instruction_t opst[] = {
		{"push", monty_nodepush}, {"pall", monty_nodepall},
		{"pint", monty_nodepint}, {"pop", monty_nodepop},
		{"swap", monty_nodeswap}, {"add", monty_nodeadd},
		{"nop", monty_nodenop}, {"sub", monty_nodesub},
		{"div", monty_nodediv}, {"mul", monty_nodemul},
		{"mod", monty_nodemod}, {"pchar", monty_nodepchar},
		{"pstr", monty_nodepstr}, {"rotl", monty_noderotl},
		{"rotr", monty_noderotr}, {"queue", monty_nodequeue},
		{"stack", monty_nodestack},
		{NULL, NULL}
	};
	unsigned int i;
	char *op;

	op = strtok(line_cont, " \n\t");
	if (op && op[0] == '#')
		return (0);

	custom_struct.argument = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode && op; i++)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, numP);
			return (0);
		}
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", numP, op);
		fclose(file_ptr);
		free(line_cont);
		freeStacks(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
