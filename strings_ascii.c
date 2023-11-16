#include "monty.h"

/**
 * printAscii - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printAscii(stack_t **stack, unsigned int lineNumber)
{
    int asciiValue;

    if (stack == NULL || *stack == NULL)
        more_error(11, lineNumber);

    asciiValue = (*stack)->n;
    if (asciiValue < 0 || asciiValue > 127)
        more_error(10, lineNumber);
    printf("%c\n", asciiValue);
}

/**
 * printStringStack - Prints a string from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printStringStack(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
    int asciiValue;
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    tmp = *stack;
    while (tmp != NULL)
    {
        asciiValue = tmp->n;
        if (asciiValue <= 0 || asciiValue > 127)
            break;
        printf("%c", asciiValue);
        tmp = tmp->next;
    }
    printf("\n");
}

