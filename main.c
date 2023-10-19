#include "monty.h"

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
		fprintf(stderr, "USAGE: monty file\n");
	}
	openfile(argv[1]);
}

