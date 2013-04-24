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
			if (btree_comparator(cur_node->data, element) == -1)
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