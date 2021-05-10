#ifndef BIN_TREE
#define BIN_TREE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
heap_t *ln(heap_t *root);
int max_prof(heap_t *node);
heap_t *find_ln(int max_prof, int cor_prof, heap_t *node);
void downt(heap_t *node);

#endif
