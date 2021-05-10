#include "binary_trees.h"

heap_t *ln(heap_t *root);
int max_prof(heap_t *node);
heap_t *find_ln(int max_prof, int cor_prof, heap_t *node);
void downt(heap_t *node);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the binary heap
 * Return: Value stored in @root (root_node->n)
 */

int heap_extract(heap_t **root)
{
	heap_t *tmp;
	heap_t *cor;
	int swp_val;

	cor = *root;

	if (*root == NULL)
		return (0);

	if (!(cor->left) && !(cor->right))
	{
		swp_val = cor->n;
		free(*root);
		*root = NULL;
		return (swp_val);
	}

	tmp = ln(*root);
	if (tmp->parent->right)
		tmp->parent->right = NULL;
	else
		tmp->parent->left = NULL;

	swp_val = cor->n;
	cor->n = tmp->n;

	downt(*root);


	free(tmp);
	return (swp_val);
}

/**
 * ln - Finds the last node of the binary heap
 * @root: Root node of the binary heap
 * Return: Pointer to the last node.
 */

heap_t *ln(heap_t *root)
{
	int prof;

	prof = max_prof(root);
	return (find_ln(prof, 1, root));
}

/**
 * max_prof - Finds the max prof of a binary tree
 * @node: Root node of the binary tree
 * Return: prof of the binary tree
 */

int max_prof(heap_t *node)
{
	int left, right;

	if (!node)
		return (0);

	left = max_prof(node->left);
	right = max_prof(node->right);

	return (((left > right) ? left : right) + 1);
}

/**
 * find_ln - Finds the node at the end of the binary tree
 * @max_prof: Max prof of the binary tree
 * @cor_prof: corent prof of the binary tree
 * @node: Root node of the binary tree
 * Return: Pointer to the node at the end of the binary tree
 */

heap_t *find_ln(int max_prof, int cor_prof, heap_t *node)
{
	heap_t *left = NULL, *right = NULL;

	if (cor_prof != max_prof)
	{
		left = find_ln(max_prof, cor_prof + 1, node->left);
		right = find_ln(max_prof, cor_prof + 1, node->right);
	}
	else
		return (node);

	return ((right) ? right : left);
}

/**
 * downt - Moves the value of @node down the tree by successively.
 * @node: Node from which the value will be sifted down the binary tree
 * Return: Void
 */

void downt(heap_t *node)
{
	heap_t *tempg = NULL;
	int tval;

	if (node->right)
		tempg = ((node->right->n > node->left->n)
				? node->right : node->left);
	else if (node->left)
		tempg = node->left;

	if (tempg)
	{
		if (tempg->n > node->n)
		{
			tval = tempg->n;
			tempg->n = node->n;
			node->n = tval;
			downt(tempg);
		}
	}
}
