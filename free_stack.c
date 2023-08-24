#include "monty.h"

/**
 * _freestack - frees a doubly linked list
 * @head: head of the stack
 */
void _freestack(stack_t *head)
{
	stack_t *current;

	for (current = head; head; head = current)
	{
		current = head->next;
		free(head);
	}
}
