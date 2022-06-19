#ifndef MONTY_H
#define MONTY_H

#define DELIMS " \t\n\r"
#define UNUSED __attribute__((unused))
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void parse(char *fileName, stack_t **head);
void nop(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void dropnl(char *src);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
int is_number(char *str);
void free_struct(void);
void free_line(void);
void dropnl(char *src);
void exec_op(char *operation, stack_t **head, unsigned int line_number);

/* extern or global variable */

/**
 * struct global_vars_s - global structure
 * @top: points to the top of the stack
 * @fp: points to the file pointer
 * @line: points to the current line of the script
 *
 */

typedef struct global_vars_s
{
	stack_t **top;
	FILE *fp;
	char *line;
} global_vars_t;

extern global_vars_t glob_var;



#endif /* MONTY_H */
