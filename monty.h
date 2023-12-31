#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head; 
typedef void (*operation_func)(stack_t **, unsigned int);

/* file functions */
int openfile(char *filename);
int readfile(FILE *fd);
int parse_line(char *buffer, int line_number, int mode);
stack_t *create_node(int n);

/* stack functions */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int test);
void print_all(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* helper functions */
void (*select_operation_func(char *op_code, int line_number))(stack_t **, unsigned int);
int valitdate_value(char *value, int line_number, int *result);
void call_func(operation_func func, char *op_code, char *value, int line_number, int *mode);
void free_nodes(void);

/* error function */
void error(int error_code, ...);

#endif
