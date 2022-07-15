#include "monty.h"

char *read_file(char *filename)
{
	int fd, bytes_read;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "can't open file");
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char *) * 1024);
	bytes_read = read(fd, buffer, 1024);
	if (bytes_read == -1)
	{
		dprintf(2, "%s file is empty", filename);
		exit(EXIT_FAILURE);
	}
	close (fd);
	return (buffer);
}

void tokenize(char *buffer, stack_t1 **stack)
{
	unsigned int line_number;
	char *token_line;
	char *token_str;
	instruction_t func;

	func = malloc(sizeof(instruction_t));
	line_number = 1;
	token_line = strtok(buffer, "\n");
	while (token_line != NULL)
	{
		push_func(token_line);
		token_str = strtok(token_line, " ");
		if (token_str != NULL)
		{
			func.opcode = token_str;
			func.f = get_op(token_str);
			f(stack, line_number);
		}
		line_number++;
		token_line = strtok(NULL, "\n");
		if (token_line == NULL)
		{
			dprintf(2, "L%d: can't execute", line_number);
			exit(EXIT_FAILURE);
		}
	}
}

void get_op(char *str)
{
	int i = 0;
	instruction_t function[] = {
		{"push", _push},
		{"pall", _pall},
		{"swap", _swap},
		{"pint", __pint},
		{"pop", _pop},
		{"add", _add},
		{NULL, NULL},
	};

	while (function[i].opcode != NULL)
	{
		if (strcmp(str, function[i].opcode) == 0)
			return (function[i].f);
		i++;
	}
}
