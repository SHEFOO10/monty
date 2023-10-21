#include "monty.h"

void print_all(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

