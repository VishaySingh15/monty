#include "monty.h"

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		first->n = first->n + second->n;
		first->next = second->next;
		free(second);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		global_vars.opcode_err = 1;
	}
}

void _nop(stack_t **stack, unsigned int line_number)
{
	if (stack && line_number)
	{
		line_number++;
	}
}
