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
 * struct stack_node - doubly linked list representation of a stack or queue
 * @value: integer value of the node
 * @previous: points to the previous node in the stack or queue
 * @next: points to the next node in the stack or queue
 *
 * Description: node structure for stack or queue operations (LIFO, FIFO)
 */
typedef struct stack_node
{
        int value;
        struct stack_node *previous;
        struct stack_node *next;
} stack_node_t;

/**
 * struct instruction - opcode and its associated function
 * @opcode: the operation code
 * @execute: function to execute the opcode
 *
 * Description: Mapping of opcodes to their functions for stack or queue operations
 */
typedef struct instruction
{
        char *opcode;
        void (*execute)(stack_node_t **stack, unsigned int lineNumber);
} instruction_t;

extern stack_node_t *stack_head;
typedef void (*opcode_function)(stack_node_t **, unsigned int);

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

