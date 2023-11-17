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

/* File Operations */
void openDocument(char *file_name);
int processLine(char *buffer, int line_number, int format);
void scanFile(FILE *);
int countFileCharacters(FILE *);
void locateFunction(char *, char *, int, int);

/* Stack Operations */
stack_t *initNode(int n);
void releaseNodes(void);
void displayStack(stack_t **, unsigned int);
void pushToStack(stack_t **, unsigned int);
void enqueueToStack(stack_t **, unsigned int);

/* Function Calling */
void executeFunction(op_func, char *, char *, int, int);

/* Stack Manipulation */
void showTop(stack_t **, unsigned int);
void removeTop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void switchNodes(stack_t **, unsigned int);

/* Math Operations with Nodes */
void sumNodes(stack_t **, unsigned int);
void subtractNodes(stack_t **, unsigned int);
void divideNodes(stack_t **, unsigned int);
void multiplyNodes(stack_t **, unsigned int);
void moduloNodes(stack_t **, unsigned int);

/* String Operations */
void printChar(stack_t **, unsigned int);
void printString(stack_t **, unsigned int);
void rotateLeft(stack_t **, unsigned int);

/* Error Handling */
void handleErr(int error_code, ...);
void additionalErr(int error_code, ...);
void stringError(int error_code, ...);
void rotateRight(stack_t **, unsigned int);


#endif
