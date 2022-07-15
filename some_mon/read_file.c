#include "monty.h"

char *read_file(char *filename)
{
	int fd, bytes_read;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char *) * 1024);
	bytes_read = read(fd, buffer, 1024);
	if (bytes_read == 0)
	{
		dprintf(2, "%s file is empty\n", filename);
		exit(EXIT_FAILURE);
	}
	close (fd);
	/*printf("%s\n", buffer);*/
	return (buffer);
}

char *tokenise(char *buffer, stack_t1 **stack, unsigned int line_number)
{
	char *token_line;
	char *token_str;
	instruction_t func;

	line_number = 1;
	token_line = strtok(buffer, "\n");
	while (token_line != NULL)
	{
		push_func(token_line);
		token_str = strtok(token_line, " ");
		if (token_str != NULL)
		{
			func.opcode = token_str;
			/*printf("%s\n", token_str);*/
			return (token_str);
		}
		line_number++;
		token_line = strtok(NULL, "\n");
		if (token_line == NULL)
		{
			dprintf(2, "L%d: can't execute\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (NULL);
}

void get_op(char *str, stack_t1 **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t function[] = {
		{"push", _push},
		{"pall", _pall},
		{"swap", _swap},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{NULL, NULL},
	};

	if (str == NULL)
	{
		dprintf(2, "no instruction found\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (function[i].opcode)
		{
			if (strcmp(str, function[i].opcode) == 0)
				function[i].f(stack, line_number);
			i++;
		}
	}
}
