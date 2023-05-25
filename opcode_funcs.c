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

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		global_vars.opcode_err = 1;
	}
}

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		global_vars.opcode_err = 1;
	}
	else
	{
		current = *stack;
		next = current->next;
		if (next)
			next->prev = NULL;
		*stack = next;
		free(current);
	}
}
