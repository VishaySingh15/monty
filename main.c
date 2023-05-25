#include "monty.h"

int main(int argc, char **argv)
{
	FILE *monty_file;
	const size_t line_size = 300;
	char *code_line;
	unsigned int line_number = 0;
	int opcode_err;
	stack_t *LIFO;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = open_file(argv[1]);
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	code_line = malloc(line_size);
	if (!code_line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	LIFO = NULL;
	while (fgets(code_line, line_size, monty_file) != NULL)
	{
		line_number++;
		if ((opcode_err = execute_opcode(code_line, &LIFO, line_number)) < 0)
		{
			exit(EXIT_FAILURE);
		}
	}
	if (code_line)
		free(code_line);
	fclose(monty_file);

	return (0);
}

FILE *open_file(char *filename)
{
	return (fopen(filename, "r"));
}