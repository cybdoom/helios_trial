#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	binary_tree_t *my_tree = btree_init();
	int *elem;

	elem = malloc(sizeof(int));
	*elem = 5;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 4;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 6;
	btree_insert(my_tree, elem);

	btree_dispose(my_tree);

	return 0;
}