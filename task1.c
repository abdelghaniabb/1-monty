#include "main.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the head of the list
 * @line_number: line_number
 * Return: void
 */
 
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
