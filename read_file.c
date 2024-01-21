#include "monty.h"
/**
 * read_file - reads a bytecode file
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 */
void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func str;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		str = get_func(line);
		if (str == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		str(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
