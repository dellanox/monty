#include "monty.h"
custom_struct_t custom_struct = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: num of arguments
* @argv: monty file_pointer location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *file_pointer;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int num_popped = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file_pointer\n");
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(argv[1], "r");
	custom_struct.file_pointer = file_pointer;
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file_pointer %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &size, file_pointer);
		custom_struct.line_content = line_content;
		num_popped++;
		if (read_line > 0)
		{
			execute(line_content, &stack, num_popped, file_pointer);
		}
		free(line_content);
	}
	free_stack(stack);
	fclose(file_pointer);
return (0);
}
