#include "monty.h"

int int_check(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
