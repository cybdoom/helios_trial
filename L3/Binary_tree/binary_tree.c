#include "binary_tree.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

binary_tree_t* btree_init(void)
{
	binary_tree_t *new_root = malloc(sizeof(binary_tree_t));
	
	if (!new_root)
	{
		return NULL;
	}

	new_root->parent = NULL;
	new_root->left_child = new_root->right_child = NULL;
	new_root->data = NULL;
	
	return new_root;
}

void btree_dispose(binary_tree_t *cur_node)
{
	if (cur_node->left_child)
	{
		btree_dispose(cur_node->left_child);
	}

	if (cur_node->right_child)
	{
		btree_dispose(cur_node->right_child);
	}

	if (!(cur_node->left_child || cur_node->right_child))
	{
		if (cur_node->parent)
		{
			if (cur_node == cur_node->parent->left_child)
			{
				cur_node->parent->left_child = NULL;
			}
			else if (cur_node == cur_node->parent->right_child)
				{
					cur_node->parent->right_child = NULL;
				}
				else
				{
					assert(0);
				}
		}

		if (cur_node->data)
		{
			free(cur_node->data);
		}

		free(cur_node);
	}
}

int btree_comparator(void *left_op, void *right_op)
{
	assert(left_op);
	assert(right_op);

	if (*((int *)left_op) < *((int *)right_op))
	{
		return -1;
	}
	else if (*((int *)left_op) > *((int *)right_op))
		{
			return 1;
		}
		else
		{
			return 0;
		}
}

void btree_insert(binary_tree_t *root, void *element)
{
	assert(root);
	assert(element);

	if (!root->data)
	{
		root->data = element;
		return;
	}
	else
	{
		binary_tree_t *cur_node = root;

		while (1)
		{
			if (btree_comparator(element, cur_node->data) == -1)
			{
				if (cur_node->left_child)
				{
					cur_node = cur_node->left_child;
				}
				else
				{
					cur_node->left_child = malloc(sizeof(binary_tree_t));
					cur_node->left_child->data = element;
					cur_node->left_child->left_child = NULL;
					cur_node->left_child->right_child = NULL;
					cur_node->left_child->parent = cur_node;
					break;
				}
			}
			else
			{
				if (cur_node->right_child)
				{
					cur_node = cur_node->right_child;
				}
				else
				{
					cur_node->right_child = malloc(sizeof(binary_tree_t));
					cur_node->right_child->data = element;
					cur_node->right_child->left_child = NULL;
					cur_node->right_child->right_child = NULL;
					cur_node->right_child->parent = cur_node;
					break;
				}
			}
		}
	}
}

void btree_remove(binary_tree_t *root, void *element)
{
	binary_tree_t *cur_node = root;
	assert(root);

	if (!root->data)
	{
		return;
	}

	while (1)
	{
		if (!(cur_node && cur_node->data))
			return;

		if (btree_comparator(element, cur_node->data) == -1)
		{
			cur_node = cur_node->left_child;
			continue;
		}

		if (btree_comparator(element, cur_node->data) == 1)
		{
			cur_node = cur_node->right_child;
			continue;
		}

		{
			if (!(cur_node->left_child || cur_node->right_child))
			{
				if (cur_node->data)
				{
					free(cur_node->data);
				}

				if (cur_node->parent)
				{
					if (cur_node == cur_node->parent->left_child)
					{
						cur_node->parent->left_child = NULL;
					}
					else if (cur_node == cur_node->parent->right_child)
						{
							cur_node->parent->right_child = NULL;
						}

					free(cur_node);
				}

				return;
			}

			if (cur_node->left_child && !cur_node->right_child)
			{
				if (cur_node->data)
				{
					free(cur_node->data);
				}

				if (cur_node->parent)
				{
					if (cur_node == cur_node->parent->left_child)
					{
						cur_node->parent->left_child = cur_node->left_child;
					}
					else if (cur_node == cur_node->parent->right_child)
						{
							cur_node->parent->right_child = cur_node->left_child;
						}

					free(cur_node);
				}

				return;
			}

			if (!cur_node->left_child && cur_node->right_child)
			{
				if (cur_node->data)
				{
					free(cur_node->data);
				}

				if (cur_node->parent)
				{
					if (cur_node == cur_node->parent->left_child)
					{
						cur_node->parent->left_child = cur_node->right_child;
					}
					else if (cur_node == cur_node->parent->right_child)
						{
							cur_node->parent->right_child = cur_node->right_child;
						}

					free(cur_node);
				}

				return;
			}

			if (cur_node->left_child && cur_node->right_child)
			{
				binary_tree_t *node_to_swap = cur_node->right_child;

				while (node_to_swap->left_child)
				{
					node_to_swap = node_to_swap->left_child;
				}

				//printf("\nNode to swap: %d", *((int *)(node_to_swap->data)));

				if (node_to_swap == node_to_swap->parent->left_child)
				{
					node_to_swap->parent->left_child = NULL;
				}
				else if (node_to_swap == node_to_swap->parent->right_child)
					{
						node_to_swap->parent->right_child = NULL;
					}

				if (cur_node->data)
				{
					free(cur_node->data);
				}
				cur_node->data = node_to_swap->data;

				free(node_to_swap);

				return;
			}
		}
	}
}

void btree_backtrack_print(binary_tree_t *cur_node)
{
	if (cur_node->left_child)
	{
		btree_backtrack_print(cur_node->left_child);
	}

	if (cur_node->right_child)
	{
		btree_backtrack_print(cur_node->right_child);
	}

	printf(" => %d", *((int *)(cur_node->data)));
}

binary_tree_t* btree_search(binary_tree_t *root, void *element)
{
	while (root && root->data)
	{
		if (btree_comparator(element, root->data) == -1)
		{
			root = root->left_child;
		}
		else if (btree_comparator(element, root->data) == 1)
		{
			root = root->right_child;
		}
		else
		{
			return root;
		}
	}

	return NULL;
}