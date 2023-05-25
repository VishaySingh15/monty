#include "monty.h"

/**
 * _add - adds top 2 items in stack
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
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

/**
 * _nop - does nothing
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	if (stack && line_number)
	{
		line_number++;
	}
}

/**
 * _sub - subtracts top 2 items in stack
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
void _sub(stack_t **stack, unsigned int line_number)
{
        stack_t *first, *second;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                second = first->next;
                first->n = first->n - second->n;
                first->next = second->next;
                free(second);
        }
        else
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _div - divides top 2 items in stack
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
void _div(stack_t **stack, unsigned int line_number)
{
        stack_t *first, *second;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                second = first->next;
                first->n = first->n / second->n;
                first->next = second->next;
                free(second);
        }
        else
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _mul - multiplies top 2 items in stack
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
void _mul(stack_t **stack, unsigned int line_number)
{
        stack_t *first, *second;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                second = first->next;
                first->n = first->n * second->n;
                first->next = second->next;
                free(second);
        }
        else
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}

/**
 * _mod - mod top 2 items in stack
 * @stack: pointer to first element in stack
 * @line_number: line number of code
 * Return: none
 */
void _mod(stack_t **stack, unsigned int line_number)
{
        stack_t *first, *second;

        if (*stack && (*stack)->next)
        {
                first = *stack;
                second = first->next;
                first->n = first->n % second->n;
                first->next = second->next;
                free(second);
        }
        else
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                global_vars.opcode_err = 1;
        }
}
