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

/**
 * nop - no operation.
 *
 * @stack: the stack.
 * @line_number: line number.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - add n of top stack node to n of next node to it.
 *
 * @stack: the stack.
 * @line_number: line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL && (*stack)->next == NULL)
	{
		error(9, line_number);
		return;
	}
	tmp->next->n += tmp->n;

	*stack = tmp->next;
	free(tmp);
}
