#include "monty.h"

/**
 * pushToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lineNumber: Integer representing the line number of the opcode (unused).
 */
void pushToStack(stack_node_t **newNode, __attribute__((unused))
unsigned int lineNumber)
{
	stack_node_t *temp;

	if (newNode == NULL || *newNode == NULL)
	exit(EXIT_FAILURE);
	if (stack_head == NULL)
	{
	stack_head = *newNode;
	return;
	}
	temp = stack_head;
	stack_head = *newNode;
	stack_head->next = temp;
	temp->previous = stack_head;
}

/**
 * displayStack - Prints all the elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Line number of the opcode (unused).
 */
void displayStack(stack_node_t **stack, __attribute__((unused))
unsigned int lineNumber)
{
	stack_node_t *temp;

	if (stack == NULL)
	exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
	printf("%d\n", temp->value);
	temp = temp->next;
	}
}

/**
 * popStack - Removes the top node of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popStack(stack_node_t **stack, unsigned int lineNumber)
{
	stack_node_t *temp;

	if (stack == NULL || *stack == NULL)
	additionalErrorHandling(7, lineNumber);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
	(*stack)->previous = NULL;
	free(temp);
}

/**
 * displayTop - Prints the top node of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void displayTop(stack_node_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
	additionalErrorHandling(6, lineNumber);
	printf("%d\n", (*stack)->value);
}
