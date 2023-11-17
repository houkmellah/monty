#include "monty.h"

/**
 * nop - Performs no operation.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}

/**
 * switchNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void switchNodes(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErr(8, lineNumber, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
	temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * sumNodes - Adds the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void sumNodes(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErr(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subtractNodes - Subtracts the second el from the top element of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void subtractNodes(stack_t **stack, unsigned int lineNumber)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErr(8, lineNumber, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divideNodes - Divides the second top el of the stack by the top element.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divideNodes(stack_t **stack, unsigned int lineNumber)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErr(8, lineNumber, "div");

	if ((*stack)->n == 0)
	additionalErr(9, lineNumber);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
