#include "monty.h"

/**
 * exe_operation - function that executes opcodes
 * @op_command: opcode commamd
 * @head: pointer to head
 * @line_number: line number
 *
 * Return: void
 */
void exec_op(char *op_command, stack_t **head, unsigned int line_number)
{
	int i;
	instruction_t all_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", stack_add},
		{"nop", nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"pchar", _pchar},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op_command, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(head, line_number);
			return;
		}
	}

	if (op_command[0] != '#' && strlen(op_command) != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
		op_command);
		free_line();
		exit(EXIT_FAILURE);
	}
}
