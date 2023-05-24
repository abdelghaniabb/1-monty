#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
	if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

void pall() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        char opcode[10];
        int value;
        int num_arguments = sscanf(line, "%s %d", opcode, &value);

        if (strcmp(opcode, "push") == 0) {
            if (num_arguments != 2) {
                fprintf(stderr, "Error at line %d: Usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error at line %d: Invalid opcode: %s\n", line_number, opcode);
            return EXIT_FAILURE;
        }

        line_number++;
    }

    fclose(file);
    return 0;
}
