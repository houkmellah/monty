#include "monty.h"

/**
 * handleError - Displays appropriate error messages based on error codes.
 * @errorCode: The error codes are as follows:
 * (1) => No file or more than one file provided to the program.
 * (2) => Provided file cannot be opened or read.
 * (3) => Invalid instruction in the file.
 * (4) => Unable to allocate more memory (malloc failed).
 * (5) => Non-integer parameter passed to "push" instruction.
 * (6) => Stack empty when attempting "pint".
 * (7) => Stack empty when attempting "pop".
 * (8) => Stack too short for operation.
 */
void handleError(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNum;
va_start(args, errorCode);
switch (errorCode)
	{
	case 1:
	fprintf(stderr, "USAGE: monty file\n");
	break;
	case 2:
	fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	break;
	case 3:
	lineNum = va_arg(args, int);
	operation = va_arg(args, char *);
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, operation);
	break;
	case 4:
	fprintf(stderr, "Error: malloc failed\n");
	break;
	case 5:
	fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	break;
	default:
	break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * additionalErrorHandling - Manages additional error scenarios.
 * @errorCode: Error codes:
 * (6) => Stack empty for "pint".
 * (7) => Stack empty for "pop".
 * (8) => Stack too short for an operation.
 * (9) => Division by zero during an operation.
 */
void additionalErrorHandling(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNum;

	va_start(args, errorCode);
	switch (errorCode)
	{
	case 6:
	fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	break;
	case 7:
	fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	break;
	case 8:
	lineNum = va_arg(args, unsigned int);
	operation = va_arg(args, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, operation);
	break;
	case 9:
	fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	break;
	default:
	break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * stringErrorHandling - Manages errors related to string operations.
 * @errorCode: Error codes:
 * (10) => Node number outside ASCII range.
 * (11) => Stack empty when attempting "pchar".
 */
void stringErrorHandling(int errorCode, ...)
{
	va_list args;
	int lineNum;

	va_start(args, errorCode);
	lineNum = va_arg(args, int);
	switch (errorCode)
	{
	case 10:
	fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
	break;
	case 11:
	fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
	break;
	default:
	break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
