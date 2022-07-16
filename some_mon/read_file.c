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

char **tokenise(char *buffer, stack_t1 **stack, unsigned int line_number)
{
	char *token_line;
	char *token_str;
	instruction_t func;
	char *line_arr[1024];
	char *str_arr[1024];
	int j = 0;
	opcode_t *temp;
	opcode_t *new;

	new = malloc(sizeof(opcode_t));
	if (!new)
		printf("malloc failed\n");

	//temp = malloc(sizeof(opcode_t));
	line_number = 1;
	token_line = strtok(buffer, "\n");
	line_arr[j] = token_line;
	j++;
	while (token_line != NULL)
	{
		token_line = strtok(NULL, "\n");
		line_arr[j] = token_line;
		j++;
	}
	//printf("%s\n", token_line);
	//token_str = strtok(NULL, "\n");
	//printf("%s: remaining buffer\n", token_str);
	j = 0;
	while (line_arr[j] != NULL)
	{
		push_func(line_arr[j]);
		token_str = strtok(line_arr[j], " ");
		str_arr[j] = token_str;
		printf("successfully read %s\n", token_str);
		if (token_line == NULL)
		{
			dprintf(2, "L%d: line empty\n", j + 1);
			break;
		}
		j++;
	}
	return (str_arr[]);
}

void get_op(char *str, stack_t1 **stack, unsigned int line_number)
{
	int i = 0;
	void (*oper)(stack_t1 **, unsigned int);
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
			{
				printf("code starts\n");
				oper = function[i].f;
				printf("Command completed\n");
			}
			i++;
		}
		oper(stack, line_number);
	}   
}
