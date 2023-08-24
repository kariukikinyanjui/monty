#include "monty.h"
/**
 * _addnode - add node to the head stack
 * @head: head of the stack
 * @n: new value
 * Return: Nothing
 */
void _addnode(stack_t **head, int n)
{
	stack_t *Nnode = malloc(sizeof(stack_t));

	if (Nnode == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	Nnode->n = n;
	Nnode->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = Nnode;
		Nnode->next = *head;
	}
	else
	{
		Nnode->next = NULL;
	}
	*head = Nnode;
}
/**
 * _queue - sets the custom_data.custom_flag to 1 indicating the program
 * should operate in queue mode rather than stack mode
 * @head: head of the stack
 * @line_no: line number
 */
void _queue(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
	custom_data.custom_flag = 1;
}
/**
 * _addqueue - function adds a new node to the tail of the stack/queue
 * based on the value of custom_data.custom_flag
 * @head: double pointer to the head of the stack
 * @n: value
 */
void _addqueue(stack_t **head, int n)
{
	stack_t *Nnode, *current;

	current = *head;
	Nnode = malloc(sizeof(stack_t));
	if (Nnode == NULL)
	{
		printf("Error\n");
	}
	Nnode->n = n;
	Nnode->next = NULL;

	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
	}
	if (!current)
	{
		*head = Nnode;
		Nnode->prev = NULL;
	}
	else
	{
		current->next = Nnode;
		Nnode->prev = current;
	}
}
