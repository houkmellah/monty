#include "monty.h"

/**
 * more_error - Handles errors related to string operations in the Monty program.
 * @err_code: The error codes are as follows:
 * (10) ~> The value inside a node is outside the ASCII bounds.
 * (11) ~> Attempt to perform a pchar operation on an empty stack.
 */
void more_error(int err_code, ...)
{
    va_list args;
    int line_num;

    va_start(args, err_code);
    line_num = va_arg(args, int);
    switch (err_code)
    {
    case 10:
        fprintf(stderr, "L%d: can't pchar, value outside ASCII bounds\n", line_num);
        break;
    case 11:
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

