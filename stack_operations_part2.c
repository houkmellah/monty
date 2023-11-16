#include "monty.h"

/**
 * noOperation - Does nothing.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void noOperation(stack_node_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}

/**
 * swapTopTwo - Swaps the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void swapTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	stack_node_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
	temp->next->previous = *stack;

	temp->next = *stack;
	(*stack)->previous = temp;
	temp->previous = NULL;
	*stack = temp;
}

/**
 * addTopTwo - Adds the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->value + (*stack)->previous->value;
	(*stack)->value = sum;
	free((*stack)->previous);
	(*stack)->previous = NULL;
}

/**
 * subtractTopTwo - Subtracts the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void subtractTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->value - (*stack)->previous->value;
	(*stack)->value = difference;
	free((*stack)->previous);
	(*stack)->previous = NULL;
}

/**
 * divideTopTwo - Divides the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divideTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "div");

	if ((*stack)->value == 0)
	additionalErrorHandling(9, lineNumber);

	(*stack) = (*stack)->next;
	quotient = (*stack)->value / (*stack)->previous->value;
	(*stack)->value = quotient;
	free((*stack)->previous);
	(*stack)->previous = NULL;
}
