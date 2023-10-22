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

/**
 * print_int - print top of the stack.
 *
 * @stack: the stack.
 * @line_number: line number.
 */

void print_int(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
		error(6, line_number);
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - pop the item from the top of stack.
 *
 * @stack: stack pointer.
 * @line_number: line number that called this funciton.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
		error(7, line_number);
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
}


/**
 * swap - swap the top node with the next.
 *
 * @stack: the stack.
 * @line_number: line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error(8, line_number);
		return;
	}
	current = *stack;
	next = current->next;

	next->prev = current->prev;
	current->next = next->next;
	next->next = current;

	*stack = next;
}
