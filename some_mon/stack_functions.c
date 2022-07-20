#include "monty.h"

void _push(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *new;
	int n = 0;
	char *arg;
	//int *push_arg;

	temp = *stack;
	new = malloc(sizeof(stack_t1));
	/*if (!temp)
	{
		dprintf(2, "Empty stack\n");
		exit(EXIT_FAILURE);
	}*/

	printf("push function called\n");

	printf("push args recieved: ");
	while (push_args[n])
	{
		printf("%s, ", push_args[n]);
		n++;
	}
	printf("\n");
	printf("push arg: %s\n", push_args[line_number - 1]);
	printf("line number assigned: %d\n", line_number);
	arg = push_args[line_number - 1];
	new->n = atoi(arg);
	new->prev = NULL;
	new->next = temp;
	if (temp != NULL)
		temp->prev = new;

	*stack = new;
}

void _pall(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	(void)line_number;

	printf("pall function called\n");
	temp = malloc(sizeof(stack_t1));
	if (!temp)
	{
		dprintf(2, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (!temp)
	{
		dprintf(2, "Empty list\n");
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void _swap(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *head;
	int temp;

	head = *stack;

	printf("swap function called\n");
	if (!(*stack))
	{
		dprintf(2, "L%d: empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (head->prev != NULL)
		head = head->prev;

	if (head->next == NULL)
	{
		dprintf(2, "L%d: can't swap,stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head->n = temp;
	head->n = (head->next)->n;
	(head->next)->n = temp;
}

void _pint(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;

	printf("pint function called\n");
	temp = *stack;
	if (!temp)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}

void _pop(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *first;

	printf("pop function called\n");
	first = *stack;
	if (!first)
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = first->next;
	temp->prev = NULL;
	first->next = NULL;

	*stack = temp;
}

void _add(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	int p, s;

	printf("add function called\n");
	temp = *stack;
	if (!temp)
	{
		dprintf(2, "L%d, can't add, empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	printf("%d", p + s);
}
