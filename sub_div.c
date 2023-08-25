#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second
 * top element of the stack
 * @head: pointer to the head of the stack/queue
 * @line_no: line number
 */
void _sub(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int diff, no_nodes;

	temp = *head;
	for (no_nodes = 0; temp != NULL; no_nodes++)
	{
		temp = temp->next;
	}
	if (no_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}
/**
 * _div - divides the second top element of the stack by the top
 * element of the stack
 * @head: pointer to the head of the stack/queue
 * @line_no: line number
 */
void _div(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d; division by zero\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	temp = current->next->n / current->n;
	current->next->n = temp;
	*head = current->next;
	free(current);
}
