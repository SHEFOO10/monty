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
		fprintf(stderr, "This is an error message printed to stderr\n");
	}
	else
	{
		readfile(fd);
		fclose(fd);
	}
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

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		mode = parse_line(buffer, line_number, mode);
	}
	free(buffer);
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
	char *operation_code, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		fprintf(stderr, "buffer is NULL");

	operation_code = strtok(buffer, delimiter);
	if (operation_code == NULL)
		return (mode);
	value = strtok(NULL, delimiter);
	printf("opcode: %s, value: %s\n", operation_code, value);
	return (mode);
}
