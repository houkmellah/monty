#include "monty.h"

/**
 * openFile - Opens a file for reading
 * @fileName: Path or name of the file to be opened
 */
void openFile(char *fileName)
{
	FILE *filePointer = fopen(fileName, "r");

	if (fileName == NULL || filePointer == NULL)
	handleError(2, fileName);

	readFile(filePointer);
	fclose(filePointer);
}

/**
 * readFile - Reads each line from a given file
 * @filePointer: File descriptor of the file to be read
 */
void readFile(FILE *filePointer)
{
	int lineNumber, storageFormat = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (lineNumber = 1; getline(&buffer, &length, filePointer) != -1;
	lineNumber++)
	{
	storageFormat = parseLine(buffer, lineNumber, storageFormat);
	}
	free(buffer);
}

/**
 * parseLine - Parses a line from a file to determine the operation
 * @buffer: Line extracted from the file
 * @lineNumber: The current line number in the file
 * @storageFormat: Format of storage (0 for stack, 1 for queue)
 * Return: 0 for stack, 1 for queue depending on the operation
 */
int parseLine(char *buffer, int lineNumber, int storageFormat)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
	handleError(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
	return (storageFormat);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
	return (0);
	if (strcmp(opcode, "queue") == 0)
	return (1);

	locateFunction(opcode, value, lineNumber, storageFormat);
	return (storageFormat);
}

/**
 * locateFunction - Locates and calls the function associated with an opcode
 * @opcode: Operation code to be executed
 * @value: Argument for the operation code
 * @lineNumber: Line number in the script
 * @storageFormat: Format of storage (0 for stack, 1 for queue)
 */
void locateFunction(char *opcode, char *value, int lineNumber,
int storageFormat)
{
	int i;
	int flag;

	instruction_t func_list[] = {
				{"push", pushToStack},
				{"pall", displayStack},
				{"pint", displayTop},
				{"pop", popStack},
				{"nop", noOperation},
				{"swap", swapTopTwo},
				{"add", addTopTwo},
				{"sub", subtractTopTwo},
				{"div", divideTopTwo},
				{"mul", multiplyTopTwo},
				{"mod", modulusTopTwo},
				{"pchar", printCharTop},
				{"pstr", printString},
				{"rotl", rotateLeft},
				{"rotr", rotateRight},
				{NULL, NULL}
	};

	if (opcode[0] == '#')
	return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
	if (strcmp(opcode, func_list[i].opcode) == 0)
	{
		executeFunction(func_list[i].execute, opcode, value, lineNumber,
		storageFormat);
		flag = 0;
		break;
	}
	}

	if (flag == 1)
	handleError(3, lineNumber, opcode);
}

/**
 * executeFunction - Executes a specific function based on the opcode
 * @func: Function to be executed
 * @opcode: Operation code
 * @value: Value associated with the operation
 * @lineNumber: Line number in the script
 * @storageFormat: Format of storage (0 for stack, 1 for queue)
 */
void executeFunction(opcode_function func, char *opcode, char *value,
int lineNumber, int storageFormat)
{
	stack_node_t *node;
	int num, isNegative = 0;

	if (strcmp(opcode, "push") == 0)
	{
	if (value == NULL)
	handleError(5, lineNumber);

	num = atoi(value);
	if (num == 0 && value[0] != '0')
	handleError(5, lineNumber);

	node = createNode(num);
	if (storageFormat == 0)
	func(&node, lineNumber);
	else if (storageFormat == 1)
	enqueue(&node, lineNumber);
	}
	else
	{
	func(&stack_head, lineNumber);
	}
}
