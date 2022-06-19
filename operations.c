#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of stack
 * @line_number: error line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	char *str_num;
	int num;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "error allocating memory");
		exit(EXIT_FAILURE);
	}
	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || is_number(str_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(top);
		exit(EXIT_FAILURE);
	}
	num = atoi(str_num);
	top->n = num;
	top->prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		*stack = top;
		top->next = NULL;
		return;
	}
	top->next = (*stack);
	(*stack)->prev = top;
	*stack = top;
}


/**
 * pall - function that prints all the values in the stack, starting from
 * the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: unused
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void) line_number;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * pint - function that prints the first element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}


/**
 * pop - function that removes the first element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = NULL;

	free(temp);
}


/**
 * swap - function that swaps the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp1, temp2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;

	(*stack)->n = temp2;
	(*stack)->next->n = temp1;

}

