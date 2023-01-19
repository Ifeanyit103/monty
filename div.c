#include "monty.h"

/**
 * _div - divides the next element by the top element in dll
 * @head: head of dll
 * @line_number: line number
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int len, result;

	len = 0;
	tmp = *head;

	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	result = tmp->next->n / tmp->n;
	tmp->next->n = result;
	*head = tmp->next;
	free(tmp);

}
