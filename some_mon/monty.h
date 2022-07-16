#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s1
{
        int n;
        struct stack_s1 *prev;
        struct stack_s1 *next;
} stack_t1;


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
        void (*f)(stack_t1 **stack, unsigned int line_number);
} instruction_t;


/**
 * struct opcodes_s - a list containing all the opcodes in a file
 * @code: The opcode strings
 */
typedef struct opcodes_s
{
	char *opcode;
	struct opcodes_s *next;
	struct opcodes_s *prev;
} opcode_t;


extern int global_argument;
extern char *global_opcode;

char *read_file(char *filename);
char **tokenise(char *str, stack_t1 **stack, unsigned int line_number);
void get_op(char *str, stack_t1 **stack, unsigned int line_number);
int push_func(char *token_line);

void _push(stack_t1 **stack, unsigned int line_number);
void _pall(stack_t1 **stack, unsigned int line_number);
void _pop(stack_t1 **stack, unsigned int line_number);
void _pint(stack_t1 **stack, unsigned int line_number);
void _swap(stack_t1 **stack, unsigned int line_number);
void _add(stack_t1 **stack, unsigned int line_number);

#endif
