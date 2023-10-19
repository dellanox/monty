#ifndef MONTY_H
#define MONTY_H

/*std libs*/
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct custom_struct_s - Custom structure to store variables
 * @argument: value
 * @file_ptr: pointer to a file (monty file), actual usuage - test
 * @line_cont: Content of a file (read lines)
 * @stack_queue_flag: Flag to switch between stack and queue
 *
 * Description: This structure holds various values used in the program.
 */
typedef struct custom_struct_s
{
	char *argument;
	FILE *file_ptr;
	char *line_cont;
	int stack_queue_flag;
}  custom_struct_t;
/*make custom datas available all the file*/
extern custom_struct_t custom_struct;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*fncs not def and not used - E*/
/*char *cust_realloc(char *block_ptr, unsigned int old_sz,*/
/*unsigned int new_sz);*/
/*ssize_t read_stdin(char **line_ptr, int file_ptr);*/
/*char  *flush_line(char *line_cont);*/

/*usr def fncs*/
void monty_nodepush(stack_t **front, unsigned int num);
void monty_nodepall(stack_t **front, unsigned int num);
void monty_nodepint(stack_t **front, unsigned int num);
int exec(char *, stack_t **, unsigned int numP, FILE *);
void freeStacks(stack_t *front);
void monty_nodepop(stack_t **front, unsigned int numP);
void monty_nodeswap(stack_t **front, unsigned int numP);
void monty_nodeadd(stack_t **front, unsigned int numP);
void monty_nodenop(stack_t **front, unsigned int numP);
void monty_nodesub(stack_t **front, unsigned int numP);
void monty_nodediv(stack_t **front, unsigned int numP);
void monty_nodemul(stack_t **front, unsigned int numP);
void monty_nodemod(stack_t **front, unsigned int numP);
void monty_nodepchar(stack_t **front, unsigned int numP);
void monty_nodepstr(stack_t **front, unsigned int numP);
void monty_noderotl(stack_t **front, unsigned int numP);
void monty_noderotr(stack_t **, unsigned int numP);
void add_Node(stack_t **front, int n);
void add_Queue(stack_t **front, int n);
void monty_nodequeue(stack_t **front, unsigned int numP);
void monty_nodestack(stack_t **front, unsigned int numP);


#endif /*MONTY_H*/
