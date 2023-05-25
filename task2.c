#include "main.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* Validate arguments */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

