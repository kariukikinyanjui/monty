#include "monty.h"

/**
 * _push - function is responsible for adding a new node with the given
 * integer value to the stack
 * @stack: double pointer to the beginning of the stack
 * @line_no: line number
 * @value: integer value
 */
void _push(stack_t **stack, unsigned int line_no, int value)
{
	stack_t *new node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * _pall - function prints all the elements in the stack
 * @stack: double pointer to head of stack
 * @line_no: line number being executed
 */
void _pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
