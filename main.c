#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the application.
 * @argc: Count of arguments.
 * @argv: Array of arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	openDocument(argv[1]);
	releaseNodes();
	return (0);
}

/**
 * initNode - Initializes a new node.
 * @n: Number to be stored in the node.
 * Return: Pointer to the new node, or NULL on failure.
 */
stack_t *initNode(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	handleErr(4);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = n;
	return (newNode);
}

/**
 * releaseNodes - Releases all nodes in the stack.
 */
void releaseNodes(void)
{
	stack_t *temp;

	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
}

/**
 * enqueueToStack - Adds a node to the end of the queue.
 * @newNode: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void enqueueToStack(stack_t **newNode, unsigned int ln)
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
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;
}
