#include "monty.h"

/**
 * handle_error - Prints appropriate error messages determined by their error code.
 * @err_code: The error codes are the following:
 * (1) => No input file or more than one file provided to the program.
 * (2) => Unable to open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation (malloc) failure.
 * (5) => Non-integer parameter passed to the "push" instruction.
 * (6) => Attempt to pint when the stack is empty.
 * (7) => Attempt to pop an empty stack.
 * (8) => Stack too short for the operation.
 * (9) => Division by zero.
 */
void handle_error(int err_code, ...)
{
    va_list args;
    char *instruction;
    int line_num;

    va_start(args, err_code);
    switch (err_code)
    {
    case 1:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 2:
        fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
        break;
    case 3:
        line_num = va_arg(args, int);
        instruction = va_arg(args, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
        break;
    case 4:
        fprintf(stderr, "Error: Memory allocation (malloc) failed\n");
        break;
    case 5:
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
        break;
    case 6:
        fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
        break;
    case 7:
        fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
        break;
    case 8:
        line_num = va_arg(args, unsigned int);
        instruction = va_arg(args, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, instruction);
        break;
    case 9:
        fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

