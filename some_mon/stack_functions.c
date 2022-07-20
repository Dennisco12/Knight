#include "monty.h"

void _push(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *new;
	int n = 0;
	char *arg;

	temp = *stack;
	new = malloc(sizeof(stack_t1));

	arg = push_args[line_number - 1];
	if (atoi(arg) == -1)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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

	temp = head->n;
	head->n = (head->next)->n;
	(head->next)->n = temp;
}

void _pint(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;

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
	stack_t1 *temp, *temp2;
	int p, s;

	temp = *stack;
	temp2 = malloc(sizeof(stack_t1));
	if (!temp2)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = temp->n;
	s = (temp->next)->n;

	temp2->n = p + s;
	//temp2 = temp->next;
	temp2->next = (temp->next)->next;
	temp2->prev = NULL;
	*stack = temp2;
	temp->next = NULL;
	//(temp->next)->prev = NULL;
}
