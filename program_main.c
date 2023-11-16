#include "monty.h"
stack_node_t *stack_head = NULL;

/**
 * main - entry point of the program
 * @argc: arguments count passed
 * @argv: array of arguments
 * Return:	O	on success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (0);
}


/**
 * createNode - Creates a new node for the stack or queue
 * @value: The integer value to be stored in the node
 * Return: Pointer to the new node, or NULL if allocation fails
 */
stack_node_t *createNode(int value)
{
	stack_node_t *newNode;

	newNode = malloc(sizeof(stack_node_t));
	if (newNode == NULL)
		handleError(4);
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->value = value;
	return (newNode);
}

/**
 * freeNodes - Frees all nodes in the stack or queue.
 */
void freeNodes(void)
{
	stack_node_t *tempNode;

	if (stack_head == NULL)
		return;

	while (stack_head != NULL)
	{
		tempNode = stack_head;
		stack_head = stack_head->next;
		free(tempNode);
	}
}

/**
 * enqueue - Adds a new node to the end of the queue
 * @newNode: Pointer to the new node
 * @lineNumber: Line number in the script (unused)
 */
void enqueue(stack_node_t **newNode, __attribute__((unused))
unsigned int lineNumber)
{
	stack_node_t *tempNode;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (stack_head == NULL)
	{
		stack_head = *newNode;
		return;
	}
	tempNode = stack_head;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = *newNode;
	(*newNode)->previous = tempNode;

}
