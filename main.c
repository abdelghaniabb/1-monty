#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
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
		/*fprintf(stderr, "Usage: %s <filename>\n", argv[0]);*/
		return (EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		/*fprintf(stderr, "Failed to open file: %s\n", argv[1]);*/
		return (EXIT_FAILURE);

	line_number = 1;
	while (fgets(line, sizeof(line), file))
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}

		if (strcmp(opcode, "push") == 0)
			push(&stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}

		line_number++;
	}

	fclose(file);
	return (0);
}
