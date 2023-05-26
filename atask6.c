#include "monty.h"
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int second_top;
	int top;
	int result;
	stack_t *new_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second_top = pop(stack, line_number);
	top = pop(stack, line_number);
	result = top - second_top;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = result;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
