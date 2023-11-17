#include "monty.h"

/**
 * printChar - Prints the ASCII value of the top node of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printChar(stack_t **stack, unsigned int lineNumber)
{
	int asciiValue;

	if (stack == NULL || *stack == NULL)
	stringError(11, lineNumber);

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
	stringError(10, lineNumber);
	printf("%c\n", asciiValue);
}

/**
 * printString - Prints a string starting from the top node of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printString(stack_t **stack, unsigned int lineNumber)
{
	int asciiValue;
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL || *stack == NULL)
	{
	printf("\n");
	return;
	}

	temp = *stack;
	while (temp != NULL)
	{
	asciiValue = temp->n;
	if (asciiValue <= 0 || asciiValue > 127)
	break;
	printf("%c", asciiValue);
	temp = temp->next;
	}
	printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
