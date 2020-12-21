#include "binary_trees.h"



/*                         Insert function                          */
/**
 * height - return the height of a binary tree
 * @tree: binary tree to go through
 * Return: 0 if it is already null or 1 or bigger of not
 */
int height(heap_t *tree)
{
	int left = 1, right = 1, result;

	if (tree == NULL)
		return (0);
	left += height(tree->left);
	right += height(tree->right);
	if (right == left)
		result = left + 1;
	else
		result = right < left ? right : left;
	return (result);
}

/**
 * insert - insert the node without heap order, just
 * as complete binary tree, completing levels one by one
 * @head: actual leaf
 * @value: value to save
 * Return: the node in the binary tree
 */
heap_t *insert(heap_t *head, int value)
{
	heap_t *new;
	int heightL, heightR;

	heightL = height(head->left);
	heightR = height(head->right);
	if (heightL == 0 || heightR == 0)
	{
		new = malloc(sizeof(heap_t));
		if (!new)
			return (NULL);
		new->n = value;
		if (heightL == 0)
			head->left = new;
		else
			head->right = new;
		new->parent = head;
		new->left = NULL;
		new->right = NULL;
	}
	else if (heightL <= heightR && heightL != 0)
		new = insert(head->left, value);
	else if (heightL > heightR)
		new = insert(head->right, value);
	return (new);
}
/*                     End of insert function                       */



/*                         Order fucntion                           */
/**
 * swap - swap two nodes in order to respect max heap order
 * @lo: leaf with smaller n
 * @hi: leaf with bigger n
 * @n: 1 if the swap was to be in left side or 2 in right side
 * @root: set the pointer to head in some circunstances
 * Return: the new updated node
 */
heap_t *swap(heap_t *lo, heap_t *hi, int n, heap_t **root)
{
	heap_t *aux = lo->parent, *loRight = lo->right, *loLeft = lo->left;
	heap_t *hiRight = hi->right, *hiLeft = hi->left;

	hi->parent = aux;
	lo->parent = hi;
	if (aux)
	{
		if (aux->left == lo)
			aux->left = hi;
		if (aux->right == lo)
			aux->right = hi;
	}
	if (hi->left)
		hi->left->parent = lo;
	if (hi->right)
		hi->right->parent = lo;
	if (n == 1)
	{
		hi->right = loRight;
		hi->left = lo;
		if (loRight)
			loRight->parent = hi;
	}
	else
	{
		hi->left = loLeft;
		hi->right = lo;
		if (loLeft)
			loLeft->parent = hi;
	}
	lo->left = hiLeft;
	lo->right = hiRight;
	if (!aux)
		*root = hi;
	return (hi);
}

/**
 * order - order the binary tree in max heap form
 * @head: actual leaf
 * @root: pointer to the head of the binary tree
 * Return: the node updated or the original
 * if it respects the order of max heap
 */
heap_t *order(heap_t *head, heap_t **root)
{
	heap_t *left, *right;

	if (head == NULL)
		return (head);
	left = order(head->left, root);
	right = order(head->right, root);
	if (!left && !right)
		return (head);
	if (left && left->n > head->n)
		return (swap(head, head->left, 1, root));
	if (right && right->n > head->n)
		return (swap(head, head->right, 2, root));
	return (head);
}
/*                     End of order function                        */


/**
 * heap_insert - inserts a value into a Max Binary Heap:
 * @root: pointer to the root of tree
 * @value: value to be inserted in new node
 * Return: pointer to the inserted node or NULL if fail
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree;

	if (*root == NULL)
	{
		tree = malloc(sizeof(heap_t));
		if (!tree)
			return (NULL);
		tree->parent = NULL;
		tree->n = value;
		tree->left = NULL;
		tree->right = NULL;
		*root = tree;
		return (tree);
	}
	tree = insert(*root, value);
	order(*root, root);
	return (tree);
}