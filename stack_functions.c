#include "monty.h"

/**
 * print_all - print all values in the stack.
 *
 * @stack: double pointer to the stack.
 * @line_number: line number.
 *
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
