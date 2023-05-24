#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str = strtok(NULL, " \t\n");
	stack_t *new_node;

	if (value_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);
printf("test: %d", value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		/*fprintf(stderr, "Error: Memory allocation failed\n");*/
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
