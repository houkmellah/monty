#include "monty.h"

/**
 * printCharTop - Prints the ASCII value at the top of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printCharTop(stack_node_t **stack, unsigned int lineNumber)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
	stringErrorHandling(11, lineNumber);

	ascii = (*stack)->value;
	if (ascii < 0 || ascii > 127)
	stringErrorHandling(10, lineNumber);
	printf("%c\n", ascii);
}

/**
 * printString - Prints a string starting from the top of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode (unused).
 */
void printString(stack_node_t **stack, __attribute__((unused))
unsigned int lineNumber)
{
	int ascii;
	stack_node_t *temp;

	if (stack == NULL || *stack == NULL)
	{
	printf("\n");
	return;
	}

	temp = *stack;
	while (temp != NULL)
	{
	ascii = temp->value;
	if (ascii <= 0 || ascii > 127)
	break;
	printf("%c", ascii);
	temp = temp->next;
	}
	printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode (unused).
 */
void rotateLeft(stack_node_t **stack, __attribute__((unused))
unsigned int lineNumber)
{
	stack_node_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	(*stack)->previous = temp;
	*stack = (*stack)->next;
	(*stack)->previous->next = NULL;
	(*stack)->previous = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode (unused).
 */
void rotateRight(stack_node_t **stack, __attribute__((unused))
unsigned int lineNumber)
{
	stack_node_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	temp->previous->next = NULL;
	temp->previous = NULL;
	(*stack)->previous = temp;
	*stack = temp;
}
