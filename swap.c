#include "monty.h"

/**
 * _swap - swa[s the values of the top two elements in the stack/queue
 * @head: pointer to the head of the stack/queue
 * @line_no: line number
 */
void _swap(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
