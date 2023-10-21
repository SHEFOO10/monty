#include "monty.h"

/**
 * select_operation_func - select the operation to use it in stack.
 *
 * @op_code: operation code.
 * @ln: line number.
 *
 * Return: function pointer for the selected function.
 */

void (*select_operation_func(char *op_code, int ln))(stack_t **, unsigned int)
{
	int i, flag = 0;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_all},
		{NULL, NULL},
	};

	if (op_code[0] == '#')
		return (NULL);

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, func_list[i].opcode) == 0)
		{
			flag = 0;
			return (func_list[i].f);
		}
	}


	if (flag == 1)
		error(4, ln, op_code);
	return (NULL);
}

/**
 * valitdate_value - validate the value for push statement.
 *
 * @value: value to be validated.
 * @line_number: line that has this value.
 * @result: pointer to variable i will put result on it.
 *
 * Return: (0) on success, (1) on fail.
 */

int valitdate_value(char *value, int line_number, int *result)
{
	if (value != NULL)
	{
		if (isdigit(value[0]) == 0 && value[0] == '-')
		{
			value = value + 1;
			*result = -(atoi(value));
			return (1);
		}
		else if (isdigit(value[0]))
		{
			*result = atoi(value);
			return (1);
		}
	}
	error(5, line_number);
	return (0);
}

/**
 * call_func - call function.
 *
 * @func: function pointer.
 * @op_code: operation code.
 * @value: value.
 * @line_number: line number.
 * @mode: pointer to mode.
 *
 * Return: (void).
 */

void call_func(
	operation_func func,
	char *op_code,
	char *value,
	int line_number,
	int *mode
	)
{
	int result, status;
	stack_t *new_node;

	if (strcmp(op_code, "push") == 0)
	{
		status = valitdate_value(value, line_number, &result);
		if (status)
		{
			new_node = create_node(result);
			func(&new_node, line_number);
		}
		else
			*mode = 3;
	}
	else
		func(&head, line_number);
}
