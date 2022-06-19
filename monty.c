#include "monty.h"

global_vars_t glob_var;
/**
 * main - man function
 * @argc: argument count
 * @argv: argument vector
 * Return: int
 */
int main(int argc, char **argv)
{
	/* initializes stack */
	stack_t *head;

	head = NULL;
	glob_var.top = &head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);
}
