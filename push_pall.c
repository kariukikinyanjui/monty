#include "monty.h"

/**
 * _push - function is responsible for adding a new node with the given
 * integer value to the stack
 * @stack: double pointer to the beginning of the stack
 * @line_no: line number
 */
void _push(stack_t **stack, unsigned int line_no)
{
	int n;

	if (custom_data.custom_arg == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(custom_data.custom_arg);

	if (custom_data.custom_flag == 0)
	{
		_addnode(stack, n);
	}
	else
	{
		_addqueue(stack, n);
	}
}
/**
 * _pall - function prints all the elements in the stack
 * @stack: double pointer to head of stack
 * @line_no: line number being executed
 */
void _pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;
	(void)line_no;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
