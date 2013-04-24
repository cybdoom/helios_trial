#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	binary_tree_t *my_tree = btree_init();
	int *elem;

	elem = malloc(sizeof(int));
	*elem = 7;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 4;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 9;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 8;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 6;
	btree_insert(my_tree, elem);

	elem = malloc(sizeof(int));
	*elem = 3;
	btree_insert(my_tree, elem);

	printf("Backtracked tree before removing:\n");
	btree_backtrack_print(my_tree);

	{
		int *element_to_remove = malloc(sizeof(int));
		*element_to_remove = 4;
		btree_remove(my_tree, element_to_remove);
	}

	printf("\nBacktracked tree after removing:\n");
	btree_backtrack_print(my_tree);
	printf("\n");

	btree_dispose(my_tree);

	return 0;
}