#include "monty.h"

/**
 * rot1 - Rotates the stack to the top.
 * @stack: pointer to topmost element of stack.
 */

void rot1(stack_t **stack)
{
	stack_t *new;

	if ((*stack != NULL) && ((*stack)->next != NULL))
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

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: pointer to topmost element of stack.
 */

void rotr(stack_t **stack)
{
	stack_t *new;

	if ((*stack != NULL) && ((*stack)->next != NULL))
	{
		new = *stack;
		while (new->next != NULL)
			new = new->next;
		new->prev->next = NULL;
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * _execute2 - Compares input command with already builtin commands.
 * @stack: Pointer to topmost element of stack.
 * @cmd: Input command.
 * @line_number: The line number of command.
 * Return: 0 on success and 1 otherwise
 */

int _execute2(stack_t **stack, char *cmd)
{
	if (strcmp(cmd, "rotr") == 0)
	{
		rotr(stack);
		return (0);
	}
	return (1);
}
