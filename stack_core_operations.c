#include "monty.h"

/**
 * multiplyTopTwo - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void multiplyTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->value * (*stack)->previous->value;
	(*stack)->value = product;
	free((*stack)->previous);
	(*stack)->previous = NULL;
}

/**
 * modulusTopTwo - Calculates the modulus of the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void modulusTopTwo(stack_node_t **stack, unsigned int lineNumber)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	additionalErrorHandling(8, lineNumber, "mod");

	if ((*stack)->value == 0)
	additionalErrorHandling(9, lineNumber);

	(*stack) = (*stack)->next;
	remainder = (*stack)->value % (*stack)->previous->value;
	(*stack)->value = remainder;
	free((*stack)->previous);
	(*stack)->previous = NULL;
}
