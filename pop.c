#include "monty.h"

/**
 * _pop - removes the top element from the stack/queue freeing
 * the memory associated with that node
 * @head: a pointer the head of the stack/queue
 * @line_no: current line number
 */
void _pop(stack_t **head, unsigned int line_no)
{
	stack_t *current;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = current->next;
	free(current);
}
