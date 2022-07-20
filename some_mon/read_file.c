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

void tokenise(char *buffer, stack_t1 **stack, unsigned int line_number)
{
	char *token_line;
	char *token_str;
	instruction_t func;
	char *line_arr[50];
	char *str_arr[50];
	char *exp[50];
	int j = 0, n = 0;
	//char **push_args;
	char *second;
	char *k = "-1", arg;

	line_number = 1;
	token_line = strtok(buffer, "\n");
	line_arr[j] = token_line;
	printf("first line: %s\n", line_arr[0]);
	j++;
	while (token_line)
	{
		token_line = strtok(NULL, "\n");
		line_arr[j] = token_line;
		printf("next line: %s\n", line_arr[j]);
		j++;
	}
	j = 0;
	while (line_arr[j])
	{
		if (line_arr[j] == NULL)
		{
			dprintf(2, "L%d: line empty\n", j + 1);
			break;
		}
		token_str = strtok(line_arr[j], " ");
		str_arr[j] = token_str;
		if (strcmp("push", token_str) == 0){
		second = strtok(NULL, " ");
		printf("%s stored successfully\n", second);
		if (second == NULL || int_check(second) == 0)
		{
			printf("push argument invalid\n");
			push_args[j] = k;
		}
		else
		{
			printf("%d: argument valid\n", atoi(second));
			exp[j] = second;
			printf("argument stored\n");
		}}
		printf("\"%s\" has been stored into array\n", str_arr[j]);
		j++;
	}
	n = 0;
	printf("push args are: ");
	while (exp[n])
	{
		push_args[n] = exp[n];
		printf("%s, ", push_args[n]);
		n++;
	}
	printf("\n");
	printf("array completely assigned, now taken to get_op\n");
	get_op(str_arr, stack);
	return;
}

void get_op(char **str, stack_t1 **stack)
{
	int i = 0;
	int j = 0, k = 0;
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

	printf("get_op function started\n");
	if (str == NULL)
	{
		dprintf(2, "no instruction found\n");
		exit(EXIT_FAILURE);
	}
	printf("array is not empty\n");
	printf("\n");
	while (str[j])
	{
		printf("checking \"%s\" against \n", str[j]);
		i = 0;
		while (function[i].opcode)
		{
			printf("%s\n", function[i].opcode);
			if (strcmp(str[j], function[i].opcode) == 0)
			{
				printf("code starts\n");
				oper = function[i].f;
				printf("Command completed\n");
				break;
			}
			i++;
		}
		oper(stack, j + 1);
		printf("operation succesfully executed\n");
		j++;
	}
	return;
}
