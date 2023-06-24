#include "monty.h"

/**
 * rot1 - Rotates the stack to the top.
 * @stack: pointer to topmost element of stack.
 */

void rot1(stack_t **stack)
{
	stack_t *new;

	if (*stack != NULL)
	{
		new = *stack;
		while (new->next != NULL)
			new = new->next;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
