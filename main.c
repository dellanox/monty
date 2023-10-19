#include "monty.h"
custom_struct_t custom_struct = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: num of arguments
* @argv: monty file_ptr location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int numP = 0;
	ssize_t read_line = 1;
	char *line_cont;
	FILE *file_ptr;
	size_t sz = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file_ptr\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	custom_struct.file_ptr = file_ptr;
	if (!file_ptr)
	{
		fprintf(stderr, "Error: Can't open file_ptr %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)

	{
		line_cont = NULL;
		read_line = getline(&line_cont, &sz, file_ptr);
		custom_struct.line_cont = line_cont;
		numP++;
		if (read_line > 0)
		{
			exec(line_cont, &stack, numP, file_ptr);
		}
		free(line_cont);
	}
	freeStacks(stack);
	fclose(file_ptr);
return (0);
}
