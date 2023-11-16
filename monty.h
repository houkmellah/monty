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

/* GLOBAL VARIABLES */
extern stack_t **global_free;

/*errors*/
void handle_error(int err_code, ...)
void more_error(int err_code, ...)
/*math operation */
void add_elements (stack_t **, unsigned int);
void subtract_elements (stack_t **, unsigned int);
void multiply_elements (stack_t **, unsigned int);
void divide_elements (stack_t **, unsigned int);
void modulo_elements (stack_t **, unsigned int);
void swap_elements (stack_t **, unsigned int);
void do_nothing (stack_t **, unsigned int);
/*string ASCII */
void printAscii (stack_t **, unsigned int);
void  printStringStack (stack_t **, unsigned i:nt);

#endif /* MONTY_H*/

