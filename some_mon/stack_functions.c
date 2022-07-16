#include "monty.h"

void _push(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	stack_t1 *new;
	int global_argument;
	(void)line_number;

	temp = *stack;

	if (!temp)
	{
		dprintf(2, "Empty stack");
		exit(EXIT_FAILURE);
	}

	printf("push function called\n");
	new = malloc(sizeof(stack_t1));

	new->n = global_argument;
	new->prev = NULL;
	new->next = temp;
	temp->prev = new;

	*stack = new;
}

void _pall(stack_t1 **stack, unsigned int line_number)
{
	stack_t1 *temp;
	(void)line_number;

	temp = *stack;
	if (!temp)
	{
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

	if (!head)
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

	temp = *stack;
	if (!temp)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d", temp->n);
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
	stack_t1 *temp;
	int p, s;

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
