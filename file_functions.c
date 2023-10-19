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

void readfile(FILE *fd)
{
	int line_number;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		printf("lineNumber: %d , value : %s", line_number, buffer);
	}
	free(buffer);
}