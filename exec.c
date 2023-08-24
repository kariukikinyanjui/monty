#include "monty.h"

/**
 * _exec - executes the opcode
 * @stack: head of a linked list (stack)
 * @line_no: line counter
 * @file: pointer to the monty file
 * @content: line content
 * Return: Nothing
 */
int _exec(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
	instruction_t opst[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{NULL, NULL}
	};
	unsigned int n = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	custom_data.custom_arg = strtok(NULL, " \n\t");

	while (opst[n].opcode && op)
	{
		if (strcmp(op, opst[n].opcode) == 0)
		{
			opst[n].f(stack, line_no);
			return (0);
		}
		n++;
	}
	if (op && opst[n].opcode == NULL)
	{
		fprintf(stderr, "L%d: unkown instruction %s\n", line_no, op);
		fclose(file);
		free(content);
		_freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
