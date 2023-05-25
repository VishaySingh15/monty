#include "monty.h"
/**
 * add_dnodeint - adds node at beginning
 * @head: pointer to first node
 * @n: data point
 * Return: pointer to added node
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *current;

	current = malloc(sizeof(stack_t));
	if (!current)
	{
		return (NULL);
	}
	current->n = n;
	current->prev = NULL;
	current->next = *head;
	*head = current;
	return (current);
}
