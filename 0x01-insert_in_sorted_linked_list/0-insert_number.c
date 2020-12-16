#include "lists.h"

/**
 * insert_node - inserts an int node in a sorted linked list
 * @head: the pointer to the head node of the list
 * @number: the number to be inserted
 * Return: the address of the new node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;

	if (!*head)
	{
		new->next = NULL;
		*head = new;
		return (*head);
	}

	temp = *head;
	if (new->n < temp->n)
	{
		new->next = *head;
		*head = new;
		return (*head);
	}

	while (temp->next != NULL && (new->n > temp->next->n))
	{
		temp = temp->next;
	}
	new->next = temp->next;
	temp->next = new;

	return (*head);
}
