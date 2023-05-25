#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	int opcode_argint;
	char *opcode_arg = global_vars.opcode_arg;

	if (!opcode_arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		global_vars.opcode_err = 1;
	}
	if ((opcode_argint = atoi(opcode_arg)) == 0 && strcmp(opcode_arg, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		global_vars.opcode_err = 1;
	}
	add_dnodeint(stack, opcode_argint);
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

        if (*stack && line_number)
	{
		current = *stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
