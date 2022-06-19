#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (!(num >= 0 && num <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}


/**
 * _rotl - function that rotates the stack to the top, the top element of the
 * stack becomes the last one, and the second top element of the stack becomes
 * the first one
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, line_number);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	tail->next = head;
	head->next = NULL;
	head->prev = tail;
}


/**
 * _rotr - function that rotates the stack to the top, the top element of the
 * stack becomes the last one, and the second top element of the stack becomes
 * the first one
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, line_number);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head = tail;
	*stack = head;
}


/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @UNUSED: line number
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *h;
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	h = *stack;
	while (h != NULL)
	{
		num = h->n;
		if (num == 0 || !(num >= 0 && num <= 127))
			break;

		printf("%c", num);
		h = h->next;
	}
	printf("\n");
}
