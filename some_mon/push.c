#include "monty.h"

int push_func(char *token_line)
{
	char *token;
	int global_argument;
	char *integer;

	token = strtok(token_line, " ");

	if (strcmp("push", token) == 0)
	{
		integer = strtok(NULL, " ");
		global_argument = atoi(integer);
		return (1);
	}
	else
		return (0);
}
