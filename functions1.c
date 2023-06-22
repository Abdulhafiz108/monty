#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to topmost element of stack.
 * @line_number: The line number of input command.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int num;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to topmost element of stack.
 * @line_number: The line number of input command.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = (*stack)->next;
	num = (new->n) + (new->next->n);
	new->next->n = num;
	free(new);
	(*stack)->prev = NULL;
}