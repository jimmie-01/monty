#include "monty.h"
/**
 * error_exit - frees the stack and exits due to error
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if  string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * _rotl - rotates list to the left
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr;
	int tmp, tmp2;

	if (*stack == NULL)
		return;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	while (ptr)
	{
		if (!ptr->next)
		{
			tmp = ptr->n;
			ptr->n = (*stack)->n;
		}
		else
		{
			tmp2 = ptr->n;
			ptr->n = tmp;
			tmp = tmp2;
		}
		ptr = ptr->prev;
	}
}
/**
 * _rotr - rotates list to the  right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *ptr1, *ptr2;
	int tmp, tmp2;

	if (*stack == NULL)
		return;

	ptr1 = *stack;
	ptr2 = *stack;
	while (ptr1->next)
		ptr1 = ptr1->next;
	while (ptr2)
	{
		if (ptr2->prev == NULL)
		{
			tmp = ptr2->n;
			ptr2->n = ptr1->n;
		}
		else
		{
			tmp2 = ptr2->n;
			ptr2->n = tmp;
			tmp = tmp2;
		}
		ptr2 = ptr2->next;

	}
}
