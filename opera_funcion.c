#include "monty.h"

/**
 * add_elements - Adds the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void add_elements(stack_t **stk, unsigned int line_num)
{
    int sum;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "add");

    (*stk) = (*stk)->next;
    sum = (*stk)->n + (*stk)->prev->n;
    (*stk)->n = sum;
    free((*stk)->prev);
    (*stk)->prev = NULL;
}

/**
 * subtract_elements - Subtracts the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void subtract_elements(stack_t **stk, unsigned int line_num)
{
    int difference;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "sub");

    (*stk) = (*stk)->next;
    difference = (*stk)->n - (*stk)->prev->n;
    (*stk)->n = difference;
    free((*stk)->prev);
    (*stk)->prev = NULL;
}
/**
 * multiply_elements - Multiplies the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void multiply_elements(stack_t **stk, unsigned int line_num)
{
    int product;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "mul");

    (*stk) = (*stk)->next;
    product = (*stk)->n * (*stk)->prev->n;
    (*stk)->n = product;
    free((*stk)->prev);
    (*stk)->prev = NULL;
}
/**
 * divide_elements - Divides the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void divide_elements(stack_t **stk, unsigned int line_num)
{
    int quotient;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "div");

    if ((*stk)->n == 0)
        handle_error(9, line_num);

    (*stk) = (*stk)->next;
    quotient = (*stk)->n / (*stk)->prev->n;
    (*stk)->n = quotient;
    free((*stk)->prev);
    (*stk)->prev = NULL;
}
