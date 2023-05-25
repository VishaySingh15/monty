#include "monty.h"

glob_t global_vars;

/**
 * execute_opcode - tokenises each line to extract opcode
 * @code_line: each line of code
 * @LIFO: stack head
 * @line_number: line number of code
 * Return: negative if fails, else positive
 */
int execute_opcode(char *code_line, stack_t **LIFO, unsigned int line_number)
{
	char *opcode;
	const char *delim = " ";
	void (*f)(stack_t **, unsigned int);

	opcode = strtok(code_line, delim);
	opcode[strcspn(opcode, "\n")] = 0;
	if (!(f = valid_opcode(opcode)))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	global_vars.opcode_arg = strtok(NULL, delim);
	global_vars.opcode_err = 0;
	f(LIFO, line_number);
	if (global_vars.opcode_err)
		return (-1);
	return (1);
}

/**
 * valid_opcode - checks if opcode is a valid command
 * @opcode - opcode string
 * Return: the function to execute opcode
 */
void (*valid_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, 
		{"swap", _swap}, {"add", _add}, 
		{"nop", _nop}, {"sub", _sub},
		{"mul", _mul}, {"div", _div},
		{"mod", _mod}, {NULL, NULL},
	};
	int count = 0;

	while(opcodes[count].opcode)
	{
		if (strcmp(opcodes[count].opcode, opcode) == 0)
		{
			return (opcodes[count].f);
		}
		count++;
	}
	return (opcodes[count].f);
}
