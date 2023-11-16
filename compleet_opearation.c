#include "monty.h"

/**
 * modulo_elements - Calculates the modulo of the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void modulo_elements(stack_t **stk, unsigned int line_num)
{
    int result;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "mod");

    if ((*stk)->n == 0)
        handle_error(9, line_num);

    (*stk) = (*stk)->next;
    result = (*stk)->n % (*stk)->prev->n;
    (*stk)->n = result;
    free((*stk)->prev);
    (*stk)->prev = NULL;
}
/**
 * swap_elements - Swaps the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void swap_elements(stack_t **stk, unsigned int line_num)
{
    stack_t *tmp;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        handle_error(8, line_num, "swap");

    tmp = (*stk)->next;
    (*stk)->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = *stk;

    tmp->next = *stk;
    (*stk)->prev = tmp;
    tmp->prev = NULL;
    *stk = tmp;
}
/**
 * do_nothing - Does nothing.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void do_nothing(stack_t **stk, unsigned int line_num)
{
    (void)stk;
    (void)line_num;
}
