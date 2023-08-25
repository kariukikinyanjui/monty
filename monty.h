#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
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
 * struct custom_data_s - variables - custom_arg, custom_file, custom_content
 * @custom_arg: value
 * @custom_file: pointer to monty file
 * @custom_content: line content
 * @custom_flag: flag change stack / queue
 */
typedef struct custom_data_s
{
	char *custom_arg;
	FILE *custom_file;
	char *custom_content;
	int custom_flag;
} custom_data_t;
extern custom_data_t custom_data;
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
void _push(stack_t **stack, unsigned int line_no);
void _pall(stack_t **stack, unsigned int line_no);
void _addnode(stack_t **head, int n);
void _freestack(stack_t *head);
void _addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int line_no);
int _exec(char *content, stack_t **stack, unsigned int line_no, FILE *file);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void _pint(stack_t **head, unsigned int line_no);
void _pop(stack_t **head, unsigned int line_no);
void _swap(stack_t **head, unsigned int line_no);
void _add(stack_t **head, unsigned int line_no);
void _nop(stack_t **head, unsigned int line_no);
void _mul(stack_t **head, unsigned int line_no);
#endif
