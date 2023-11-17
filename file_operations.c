#include "monty.h"

/**
 * openDocument - Opens a specified file.
 * @fileName: The file name/path.
 * Return: void.
 */
void openDocument(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
	handleErr(2, fileName);

	scanFile(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * scanFile - Reads a file and processes its contents.
 * @fileDescriptor: Pointer to the file descriptor.
 * Return: void.
 */
void scanFile(FILE *fileDescriptor)
{
	int lineNum, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNum = 1; getline(&buffer, &len, fileDescriptor) != -1; lineNum++)
	{
	format = processLine(buffer, lineNum, format);
	}
	free(buffer);
}

/**
 * processLine - Processes each line to determine the function call.
 * @buffer: Line from the file.
 * @lineNum: Line number.
 * @format: Storage format (0 for stack, 1 for queue).
 * Return: Returns 0 if opcode is stack, 1 if queue.
 */
int processLine(char *buffer, int lineNum, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	handleErr(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
	return (0);
	if (strcmp(opcode, "queue") == 0)
	return (1);

	locateFunction(opcode, value, lineNum, format);
	return (format);
}

/**
 * locateFunction - Finds and executes the appropriate function.
 * @opcode: Opcode.
 * @value: Opcode argument.
 * @ln: Line number.
 * @format: Storage format (0 for stack, 1 for queue).
 * Return: void.
 */
void locateFunction(char *opcode, char *value, int ln, int format)
{
	int i, flag;
	instruction_t funcList[] = {
				{"push", pushToStack}, {"pall", displayStack},
				{"pint", showTop}, {"pop", removeTop},
				{"nop", nop}, {"swap", switchNodes},
				{"add", sumNodes}, {"sub", subtractNodes},
				{"div", divideNodes}, {"mul", multiplyNodes},
				{"mod", moduloNodes}, {"pchar", printChar},
				{"pstr", printString}, {"rotl", rotateLeft},
				{"rotr", rotateRight}, {NULL, NULL}
	};

	if (opcode[0] == '#')
	return;

	for (flag = 1, i = 0; funcList[i].opcode != NULL; i++)
	{
	if (strcmp(opcode, funcList[i].opcode) == 0)
	{
		executeFunction(funcList[i].f, opcode, value, ln, format);
		flag = 0;
	}
	}
	if (flag == 1)
	handleErr(3, ln, opcode);
}

/**
 * executeFunction - Executes the required function.
 * @func: Pointer to the function to be called.
 * @op: Opcode string.
 * @val: Numeric value string.
 * @ln: Line number.
 * @format: Format specifier (0 for stack, 1 for queue).
 */
void executeFunction(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
	if (val != NULL && val[0] == '-')
	{
		val += 1;
		flag = -1;
	}
	if (val == NULL)
	handleErr(5, ln);
	for (i = 0; val[i] != '\0'; i++)
	{
		if (!isdigit(val[i]))
		handleErr(5, ln);
	}
	node = initNode(atoi(val) * flag);
	if (format == 0)
	func(&node, ln);
	else if (format == 1)
	enqueueToStack(&node, ln);
	}
	else
	func(&head, ln);
}


