#include "monty.h"

void freelist(stack_t1 *stack)
{
	stack_t1 *temp;

	temp = stack;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}
