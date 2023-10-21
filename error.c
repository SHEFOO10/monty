#include "monty.h"

/**
 * error - to print errors.
 *
 * @error_code: error code.
 *
 * Return: Void.
 */
void error(int error_code, ...)
{
	va_list list;
	int line_number;

	va_start(list, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(list, char *));
			break;
		case 3:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 4:
			line_number = va_arg(list, int);
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number,
				va_arg(list, char *));
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(list, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty", va_arg(list, int));
			break;
		default:
			break;
	}
	va_end(list);
}
