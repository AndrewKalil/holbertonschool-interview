#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp;
	int i, size = 0;
	listint_t *array[3000];

	if (!head)
		return (0);
	if (!(*head) || !(*head)->next)
		return (1);
	for (i = 0; i < 3000; i++)
		array[i] = NULL;
	tmp = *head;
	while (tmp)
	{
		array[size] = tmp;
		size++;
		tmp = tmp->next;
	}
	for (i = 0; i < (size / 2); i++)
	{
		if (array[i]->n != array[size - 1 - i]->n)
		{
			return (0);
		}
	}
	return (1);
}