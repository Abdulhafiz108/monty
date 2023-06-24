#include "monty.h"

/**
 * sub - Subtract the value of topmost elements from second topmost element.
 * @stack: Pointer to the topmost stack.
 * @line_number: The line number of command.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int divi;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	new = new->next;
	divi = (new->n) / (new->prev->n);
	new->n = divi;
	new->prev = NULL;
	free(*stack);
	*stack = new;
}

/**
 * mul - Multiplies the value of topmost element with second topmost element.
 * @stack: Pointer to the topmost stack.
 * @line_number: The line number of command.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int mul;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;
	new = new->next;
	mul = (new->n) * (new->prev->n);
	new->n = mul;
	new->prev = NULL;
	free(*stack);
	*stack = new;
}