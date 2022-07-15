#include "monty.h"

int push_func(char *token_line)
{
	char *str;
	char *token;
	int global_argument;
	char *integer;

	str = "push";
	token = strtok(token_line, " ");

	if (strcmp("push", token) == 0)
	{
		integer = strtok(NULL, " ");
		global_argument = atoi(integer);
		/*printf("%d\n", global_argument);*/
		return (1);
	}
	else
		return (0);
}
