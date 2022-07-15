#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *buffer;
	char *str;
	stack_t1 **stack;
	unsigned int line_number;

	buffer = read_file(argv[1]);
	str = tokenise(buffer, stack, line_number);
	get_op(str, stack, line_number);

	free(stack);

	return (0);
}
