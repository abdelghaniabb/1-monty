#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the header of the list
 * @line_number: line_number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str;
	stack_t *new_node;

	value_str = strtok(NULL, " \t\n");

	if (value_str == NULL || _isdigit(value_str) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
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
/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the header of the list
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _isdigit - Checks if a string represents an integer
 * @str: String to check
 * Return: 1 if string is an integer, 0 otherwise
 */
int _isdigit(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		return (0);
	}

	return (1);
}

