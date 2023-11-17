#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void openFile(char *fileName);
int parseLine(char *buffer, int lineNumber, int format);
void readFile(FILE *filePointer);
int characterCount(FILE *filePointer);
void locateFunction(char *opcode, char *buffer, int lineNumber, int format);

/* Stack operations */
stack_node_t *createNode(int value);
void freeNodes(void);
void displayStack(stack_node_t **stack, unsigned int lineNumber);
void pushToStack(stack_node_t **stack, unsigned int value);
void enqueue(stack_node_t **stack, unsigned int value);

void executeFunction(opcode_function func, char *buffer, char *opcode, int lineNumber, int format);

void displayTop(stack_node_t **stack, unsigned int lineNumber);
void popStack(stack_node_t **stack, unsigned int lineNumber);
void noOperation(stack_node_t **stack, unsigned int lineNumber);
void swapTopTwo(stack_node_t **stack, unsigned int lineNumber);

/* Mathematical operations on nodes */
void addTopTwo(stack_node_t **stack, unsigned int lineNumber);
void subtractTopTwo(stack_node_t **stack, unsigned int lineNumber);
void divideTopTwo(stack_node_t **stack, unsigned int lineNumber);
void multiplyTopTwo(stack_node_t **stack, unsigned int lineNumber);
void modulusTopTwo(stack_node_t **stack, unsigned int lineNumber);

/* String operations */
void printCharTop(stack_node_t **stack, unsigned int lineNumber);
void printString(stack_node_t **stack, unsigned int lineNumber);
void rotateLeft(stack_node_t **stack, unsigned int lineNumber);

/* Error handling */
void handleError(int errorCode, ...);
void additionalErrorHandling(int errorCode, ...);
void stringErrorHandling(int errorCode, ...);
void rotateRight(stack_node_t **stack, unsigned int lineNumber);

#endif /* MONTY_H */
