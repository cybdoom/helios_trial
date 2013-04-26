#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

void FillTree(binary_tree_t *root);
void Search(binary_tree_t *root, int value);

int main(void)
{
	binary_tree_t *my_tree = btree_init();
	
	/* Fill tree with => 7 => 4 => 9 => 8 => 6 => 3 */
	FillTree(my_tree);

	/* Remove the element with the value of "4" */
	{
		int *element_to_remove = malloc(sizeof(int));
		*element_to_remove = 7;
		printf("\nRemoving element \"7\":\n");
		btree_remove(my_tree, element_to_remove);
		btree_backtrack_print(my_tree);
		free(element_to_remove);
	}

	/* Search for the element with value of "4". Prints found node's children */
	Search(my_tree, 4);

	/* Search for the element with value of "7". Prints found node's children */
	Search(my_tree, 7);

	/* Free resourses allocated for the tree */
	btree_dispose(my_tree);

	printf("\n");

	return 0;
}

void FillTree(binary_tree_t *root)
{
	int *elem;

	elem = malloc(sizeof(int));
	*elem = 7;
	btree_insert(root, elem);
	printf("Adding element \"7\":\n");
	btree_backtrack_print(root);

	elem = malloc(sizeof(int));
	*elem = 4;
	printf("\nAdding element \"4\":\n");
	btree_insert(root, elem);
	btree_backtrack_print(root);

	elem = malloc(sizeof(int));
	*elem = 9;
	printf("\nAdding element \"9\":\n");
	btree_insert(root, elem);
	btree_backtrack_print(root);

	elem = malloc(sizeof(int));
	*elem = 8;
	printf("\nAdding element \"8\":\n");
	btree_insert(root, elem);
	btree_backtrack_print(root);

	elem = malloc(sizeof(int));
	*elem = 6;
	printf("\nAdding element \"6\":\n");
	btree_insert(root, elem);
	btree_backtrack_print(root);

	elem = malloc(sizeof(int));
	*elem = 3;
	printf("\nAdding element \"3\":\n");
	btree_insert(root, elem);
	btree_backtrack_print(root);
}

void Search(binary_tree_t *root, int value)
{
	int *element_to_search = malloc(sizeof(int));
	binary_tree_t *found_node;
	*element_to_search = value;
	printf("\nSearching for element \"%d\"... ", value);
	found_node = btree_search(root, element_to_search);
	if (found_node)
	{
		printf("Node was found. Children values:\n");
	
		if (found_node->left_child && found_node->left_child->data)
		{
			printf("Left child = %d\n", *((int *)(found_node->left_child->data)));
		}
		else
		{
			printf("Left child: NULL\n");	
		}
		if (found_node->right_child && found_node->right_child->data)
		{
			printf("Right child = %d", *((int *)(found_node->right_child->data)));
		}
		else
		{
			printf("Right child: NULL");	
		}
	}
	else
	{
		printf("Node with such value was not found");
	}

	free(element_to_search);
}