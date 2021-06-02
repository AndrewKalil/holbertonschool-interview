#include "lists.h"

/**
 * find_listint_loop - Detects if there's a loop and finds where.
 * @head: Head of the singly linked list.
 *
 * Return: The position of the node where the loop is found otherwise NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tt, *Hare;
	int flag = 0;

	if (!head || !head->next)
		return (NULL);

	tt = head->next;
	Hare = head->next->next;

	while (tt && Hare && Hare->next)
	{

		tt = tt->next;
		Hare = Hare->next->next;

		if (tt == Hare)
		{
			flag = 1;
			break;
		}

	}

	if (flag == 1)
	{
		for (tt = head; tt != Hare; tt = tt->next, Hare = Hare->next)
			;

		return (Hare);
	}

	return (NULL);

}
