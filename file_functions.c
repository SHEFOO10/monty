#include "monty.h"

/**
 * openfile - test existance of the file and open it for read.
 *
 * @filename: filename to open it.
 *
 * Return: nothing.
 */

void openfile(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
	{
		error(2, filename);
		exit(EXIT_FAILURE);
	}

	readfile(fd);
	fclose(fd);

}

/**
 * readfile - read a file.
 *
 * @fd: pointer to file descriptor.
 *
 * Return: void.
 */

void readfile(FILE *fd)
{
	int line_number, mode = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; (int) getline(&buffer, &len, fd) != -1; line_number++)
	{
		mode = parse_line(buffer, line_number, mode);
		if (mode == 3)
			break;
	}
	free(buffer);
	free_nodes();
}


/**
 * parse_line - extract op_code and value from the line.
 *
 * @buffer: the line i will parse.
 * @line_number: if errors occured i'll return line number with the error.
 * @mode: (0) for stack, (1) for queue.
 *
 * Return: (0) for stack, (1) for queue.
 */

int parse_line(char *buffer, int line_number, int mode)
{
	char *operation_code, *value, *token;
	const char *delimiter = "\n ";
	operation_func func;

	operation_code = strtok(buffer, delimiter);
	if (operation_code == NULL)
		return (mode);
	value = strtok(NULL, delimiter);

	while ((token = strtok(NULL, delimiter)))
	{
		if (strcmp(token, "stack") == 0)
			mode = 0;
		if (strcmp(token, "queue") == 0)
			mode = 1;
		token = strtok(NULL, delimiter);
	}
	func = select_operation_func(operation_code, line_number);
	if (func != NULL)
		call_func(func, operation_code, value, line_number);
	else
		mode = 3;
	return (mode);
}
