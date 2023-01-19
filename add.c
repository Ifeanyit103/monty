#include "monty.h"


/**
 * _add - adds the top number and the next number in stacked dll
 * @head: head of am stack dll
 * @line_number: line number
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int len;
	int sum;

	tmp = *head;
	/*if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}*/
	for (len = 0; tmp != NULL; len++)
		tmp = tmp->next;
	if (head == NULL || (*head)->next == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = (*head)->next->n + (*head)->n;
	_pop(head, line_number);
	(*head)->n = sum;

}
