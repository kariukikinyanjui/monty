#include "monty.h"
/**
 * _pint - prints the value of the top element of the stack or queue
 * @head: head of the stack
 * @line_no: line number
 */
void _pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(custom_data.custom_file);
		free(custom_data.custom_content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
