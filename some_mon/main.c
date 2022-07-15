#include "monty.h"

int main(int argc, char *argv[])
{
	(void)argc;
	char *buffer;
	stack_t1 **stack;
	unsigned int line_number;

	buffer = read_file(argv[1]);
	tokenise(buffer);

	return (0);
}
