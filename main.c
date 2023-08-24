#include "monty.h"
custom_data_t custom_data = {NULL, NULL, NULL, 0};

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCESS
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t _line = 1;
	stack_t *stack = NULL;
	unsigned int line_no = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	custom_data.custom_file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (_line > 0)
	{
		content = NULL;
		_line = getline(&content, &size, file);
		custom_data.custom_content = content;
		line_no++;

		if (_line > 0)
		{
			_exec(content, &stack, line_no, file);
		}
		free(content);
	}
	_freestack(stack);
	fclose(file);
	return (0);
}
