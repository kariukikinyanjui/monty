#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the
 * top element of the stack
 * @head: pointer to the head of the stack/queue
 * @line_no: line number
 */
void _mul(stack_t **head, unsigned int line_no)
{
	stack_t *current;
	int count = 0, temp;

	current = *head;
	while (current)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d; can't mul, stack too short\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->next->n * current->n;
	current->next->n = temp;
	*head = current->next;
	free(current);
}
