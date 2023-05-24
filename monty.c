#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL; /* Global stack variable */

void push(stack_t **stack, unsigned int line_number) {
	int value;
    char *value_str = strtok(NULL, " \t\n");
    stack_t *new_node;

    if (value_str == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(value_str);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack == NULL) {
        *stack = new_node;
    } else {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}

void pall(stack_t **stack) {
    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
	FILE *file;
	char line[100];
	int line_number = 1;
	
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    
    

    while (fgets(line, sizeof(line), file)) {
        char *opcode = strtok(line, " \t\n");

        if (opcode == NULL || opcode[0] == '#') {
            line_number++;
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            push(&stack, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }

        line_number++;
    }

    fclose(file);
    return 0;
}
