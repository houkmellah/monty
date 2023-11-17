#include "monty.h"

/**
 * handleErr - Handles errors and prints appropriate error messages.
 * @error_code: Error codes with specific meanings:
 * (1) File issues.
 * (2) File open/read issues.
 * (3) Invalid instructions in file.
 * (4) Memory allocation failure.
 * (5) Non-integer parameters for "push".
 * (6) Empty stack for "pint".
 * (7) Empty stack for "pop".
 * (8) Insufficient stack length for operations.
 */
void handleErr(int error_code, ...)
{
	va_list args;
	char *instruction;
	int lineNum;

	va_start(args, error_code);
	switch (error_code)
	{
	case 1:
	fprintf(stderr, "USAGE: monty file\n");
	break;
	case 2:
	fprintf(stderr, "Error: Can't open file %s\n",
		va_arg(args, char *));
	break;
	case 3:
	lineNum = va_arg(args, int);
	instruction = va_arg(args, char *);
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, instruction);
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
	releaseNodes();
	exit(EXIT_FAILURE);
}

/**
 * additionalErr - Manages additional error scenarios.
 * @error_code: Error codes for specific situations:
 * (6) Empty stack for "pint".
 * (7) Empty stack for "pop".
 * (8) Inadequate stack length.
 * (9) Division by zero errors.
 */
void additionalErr(int error_code, ...)
{
	va_list args;
	char *operation;
	int lineNum;

	va_start(args, error_code);
	switch (error_code)
	{
	case 6:
	fprintf(stderr, "L%d: can't pint, stack empty\n",
		va_arg(args, int));
	break;
	case 7:
	fprintf(stderr, "L%d: can't pop an empty stack\n",
		va_arg(args, int));
	break;
	case 8:
	lineNum = va_arg(args, unsigned int);
	operation = va_arg(args, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, operation);
	break;
	case 9:
	fprintf(stderr, "L%d: division by zero\n",
		va_arg(args, unsigned int));
	break;
	default:
	break;
	}
	releaseNodes();
	exit(EXIT_FAILURE);
}

/**
 * stringError - Manages errors related to string operations.
 * @error_code: Error codes for specific string issues:
 * (10) Node number outside ASCII range.
 * (11) Empty stack issues.
 */
void stringError(int error_code, ...)
{
	va_list args;
	int lineNum;

	va_start(args, error_code);
	lineNum = va_arg(args, int);
	switch (error_code)
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
	releaseNodes();
	exit(EXIT_FAILURE);
}
