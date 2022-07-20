#include "monty.h"

char **push_args;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *buffer;
	stack_t1 *stack;
	unsigned int line_number;
	int i = 0;
	int *str;

	stack = NULL;
	buffer = read_file(argv[1]);
	//printf("%s\n", buffer);
	tokenise(buffer, &stack, line_number);
	/*while (str)
	{
		push_arg[i] = str[i];
		i++;
	}*/
	/*while (str->prev != NULL)
		str = str->prev;*/

	/*while (str != NULL)
	{
		printf("%s\n", str->opcode);
		str = str->next;
	}*/
	//get_op(str, stack, line_number);

	printf("program completed\n");
	freelist(stack);

	return (0);
}
