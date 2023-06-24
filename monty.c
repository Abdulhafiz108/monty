#include "monty.h"
/**
 * main - entry point
 * @argc: Argument count.
 * @argv: Argument variable.
 * Return: EXIT_SUCCESS on success and otherwise on failure.
 */

int main(int argc, char *argv[])
{
	char line[MAX_SIZE];
	char *cmd;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *file;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';
		if (line != NULL)
		{
			cmd = strtok(line, " ,$");
			_execute(&stack, cmd, line_number);
		}
	}
	_free(&stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
