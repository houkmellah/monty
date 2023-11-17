#include "monty.h"

/**
 * pushToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void pushToStack(stack_t **newNode, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (newNode == NULL || *newNode == NULL)
	exit(EXIT_FAILURE);
	if (head == NULL)
	{
	head = *newNode;
	return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * displayStack - Displays all nodes in the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void displayStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL)
	exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
	printf("%d\n", temp->n);
	temp = temp->next;
	}
}

/**
 * removeTop - Removes the top node of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void removeTop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	additionalErr(7, lineNumber);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * showTop - Prints the top element of the stack.
 * @stack: Pointer to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void showTop(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
	additionalErr(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
