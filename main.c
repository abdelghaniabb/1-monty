#include "main.h"
/**
 * handle - handle opcodes
 * @stack: the head of the list
 * @opcode: opcode
 * @L_N: line_number
 * @file: file
 * Return: void
 */
void handle(stack_t **stack, char *opcode, unsigned int L_N, FILE *file)
{
	int line_number = L_N;

	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);

	else if (strcmp(opcode, "pall") == 0)
		pall(stack);

	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);

	else
	{
		fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
/**
 * main - check code
 * @argc: argc
 * @argv: argv
 * Return: int
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char line[100];
	int line_number;
	char *opcode;

	if (argc != 2)
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
	line_number = 1;
	while (fgets(line, sizeof(line), file))
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}

		handle(&stack, opcode, line_number, file);

		line_number++;
	}

	fclose(file);
	return (0);
}
