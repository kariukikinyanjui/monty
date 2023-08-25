#include "monty.h"

/**
 * _add - adds the values of the top two elements in the stack/queue
 * @head: pointer to the head of the stack
 * @line_no: line number
 */
void _add(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->n + current->next->n;
	current->next->n = temp;
	*head = current->next;
	free(current);
}
