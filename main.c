#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCESS
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, *arg, *line = NULL;
	size_t len = 0;
	unsigned int line_no = 0;
	stack_t *temp, *stack = NULL;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (!opcode)
			continue;
		if (strcmp(opcode, "_push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (!arg)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_no);
				fclose(file);
				free(line);
				while (stack)
				{
					temp = stack;
					stack = stack->next;
					free(temp);
				}
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			_push(&stack, line_no, value);
		}
		else if (strcmp(opcode, "_pall") == 0)
		{
			_pall(&stack, line_no);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
			fclose(file);
			free(line);
			while (stack)
			{
				temp = stack;
				stack = stack->next;
				free(temp);
			}
			exit(EXIT_FAILURE);

		}
	}


}
