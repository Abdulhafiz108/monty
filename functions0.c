#include "monty.h"

/**
 * _execute - It executes the input commands.
 * @stack: List containing inputs.
 * @cmd: Holds the input command.
 * @line_number: The line number of command.
 * Return: 0 on success and EXIT_FAILURE otherwise.
 */

int _execute(stack_t **stack, char *cmd, int line_number)
{
	if (strcmp(cmd, "push") == 0)
	{
		push(stack, line_number);
		return (0);
	}
	if (strcmp(cmd, "pall") == 0)
	{
		pall(*stack);
		return (0);
	}
	if (strcmp(cmd, "pint") == 0)
	{
		pint(*stack, line_number);
		return (0);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}

/**
 * push - Adds an element to the top of the stack.
 * @stack: The list containing the elements of the stack.
 * @line_number: The line number of command.
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;
	char *arg = NULL;
	int i;

	arg = strtok(NULL, " ,$");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - Prints all the elements of a stack.
 * @stack: List containing elements of the stack.
 */

void pall(stack_t *stack)
{
	stack_t *new;

	if (stack != NULL)
	{
		new = stack;
		while (new)
		{
			printf("%d\n", new->n);
			new = new->next;
		}
	}
}

/**
 * pint - Prints the top most value of stack.
 * @stack: List containing elements of the stack.
 * @line_number: Line number of command.
 */

void pint(stack_t *stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}
