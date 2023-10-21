#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry Point.
 *
 * @argc: argument count.
 * @argv: array of arguments.
 *
 * Return: (0) on Success, (1) if error occured.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error(1);
		exit(EXIT_FAILURE);
	}
	openfile(argv[1]);
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(3);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

void free_nodes(void)
{
	stack_t *tmp = head;
	while (tmp)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}