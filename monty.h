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
 * @file_pointer: pointer to a file (monty file), actual usuage - test
 * @line_content: Content of a file (read lines)
 * @stack_queue_flag: Flag to switch between stack and queue
 *
 * Description: This structure holds various values used in the program.
 */
typedef struct custom_struct_s
{
	char *argument;
	FILE *file_pointer;
	char *line_content;
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
/*ssize_t read_stdin(char **line_ptr, int file_pointer);*/
/*char  *flush_line(char *line_content);*/

/*usr def fncs*/
void f_push(stack_t **front, unsigned int num);
void f_pall(stack_t **front, unsigned int num);
void f_pint(stack_t **front, unsigned int num);
int execute(char *line_content, stack_t **front, unsigned int num_popped,
FILE *file_pointer);
void free_stack(stack_t *front);
void f_pop(stack_t **front, unsigned int num_popped);
void f_swap(stack_t **front, unsigned int num_popped);
void f_add(stack_t **front, unsigned int num_popped);
void f_nop(stack_t **front, unsigned int num_popped);
void f_sub(stack_t **front, unsigned int num_popped);
void f_div(stack_t **front, unsigned int num_popped);
void f_mul(stack_t **front, unsigned int num_popped);
void f_mod(stack_t **front, unsigned int num_popped);
void f_pchar(stack_t **front, unsigned int num_popped);
void f_pstr(stack_t **front, unsigned int num_popped);
void f_rotl(stack_t **front, unsigned int num_popped);
void f_rotr(stack_t **front, __attribute__((unused)) unsigned int num_popped);
void addnode(stack_t **front, int n);
void addqueue(stack_t **front, int n);
void f_queue(stack_t **front, unsigned int num_popped);
void f_stack(stack_t **front, unsigned int num_popped);


#endif /*MONTY_H*/
