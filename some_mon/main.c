#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *buffer;
	char **str;
	stack_t1 **stack;
	unsigned int line_number;

	buffer = read_file(argv[1]);
	//printf("%s\n", buffer);
	str = tokenise(buffer, stack, line_number);
	/*while (str->prev != NULL)
		str = str->prev;*/

	printf("head gotten successfully\n");
	/*while (str != NULL)
	{
		printf("%s\n", str->opcode);
		str = str->next;
	}*/
	//get_op(str, stack, line_number);

	free(stack);

	return (0);
}
