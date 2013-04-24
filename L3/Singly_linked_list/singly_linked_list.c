#include "singly_linked_list.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

list_t* list_init()
{
	/* Allocate memory for head */
	list_t *head = malloc(sizeof(list_t));
	assert(head);
	head->data = NULL;
	head->next = NULL;

	return head;
}

void list_free(list_t *list)
{
	assert(list);
	list_t *p_next;
	while (list)
	{
		assert(list);
		p_next = list->next;
		
		/* Free memory occupied by data */
		if (list->data)
		{
			free(list->data);
			list->data = NULL;
		}
		
		/* Free memory occupied by node */
		free(list);
		
		/* Go to the next node */
		list = p_next;
	}
}

size_t list_size(list_t *list)
{
	assert(list);

	size_t size = 0;
	
	/* Count each non-empry node */
	while (list && list->data)
	{
		size++;
		list = list->next;
	}

	return size;
}

list_t* list_insert_front(list_t *list, void *element)
{
	assert(list);
	assert(element);
	if (!list->data)
	/* If the list is empty, write given data to head node */
	{
		/* Create reference to the given data in the current head */
		list->data = element;

		return list;
	}
	else
	{
		/* Allocate memory for the new head */
		list_t *new_head = malloc(sizeof(list_t));

		/* Create reference to the given data in the new head */
		new_head->data = element;

		/* Modify links */
		new_head->next = list;

		return new_head;
	}
}

list_t* list_insert_after(list_t *list, void *element, int pos)
{
	assert(list);
	assert(element);
	assert(pos >= 0 && pos <= list_size(list));

	if (pos == 0)
	{
		return list_insert_front(list, element);
	}
	else
	{
		/* Go to pos-th element of the list */
		int cur_pos = 1;
		list_t *cur_node = list;

		while (cur_pos < pos)
		{
			cur_node = cur_node->next;
			cur_pos++;
		}
		
		/* Remember the old link */
		list_t *p_next = cur_node->next;

		/* Allocate the new node after the pos-th node*/
		cur_node->next = malloc(sizeof(list_t));
		assert(cur_node->next);

		/* Create reference to the given data in the new node */ 
		cur_node->next->data = element;

		/* Modify links */
		cur_node->next->next = p_next;

		return list;
	}
}

list_t* list_insert_rear(list_t *list, void *element)
{
	assert(list);
	assert(element);

	if (list_size(list) == 0)
	{
		return list_insert_front(list, element);
	}
	else
	{
		list_t *cur_node = list;

		while (cur_node->next)
		{
			cur_node = cur_node->next;
		}

		cur_node->next = malloc(sizeof(list_t));
		cur_node->next->data = element;
		cur_node->next->next = NULL;

		return list;
	}
}

list_t* list_remove_front(list_t *list)
{
	assert(list);

	if (list_is_empty(list))
	{
		return list;
	}

	free(list->data);
	list->data = NULL;

	if (!list->next)
	{
		return list;
	}
	else
	{
		list_t *p_next = list->next;
		free(list);
		return p_next;
	}
}

list_t* list_remove_rear(list_t *list)
{
	assert(list);

	if (list_is_empty(list))
	{
		return list;
	}

	if (!list->next)
	{
		return list_remove_front(list);
	}
	else
	{
		list_t *cur_node = list;

		while (cur_node->next->next)
		{
			cur_node = cur_node->next;
		}

		free(cur_node->next->data);
		cur_node->next->data = NULL;

		free(cur_node->next);
		cur_node->next = NULL;
	}
}

list_t* list_remove_any(list_t *list, void *element, int remove_all_instances)
{
	list_t *cur_node = list;

	assert(list);
	assert(element);

	if (list_is_empty(list))
	{
		return list;
	}

	if (*((int *)(list->data)) == *((int *)element))
	{
		if (!remove_all_instances)
		{
			return list_remove_front(list);
		}
		else
		{
			return list_remove_any(list_remove_front(list), element, 1);
		}
	}
	else
	{
		while (cur_node->next)
		{
			if (cur_node->next->data && *((int *)(cur_node->next->data)) == *((int *)element))
			{
				
				list_t *node_to_rm = cur_node->next;
				free(cur_node->next->data);
				cur_node->next = cur_node->next->next;
				free(node_to_rm);
			}
			else
			{
				cur_node = cur_node->next;
			}

			if (!remove_all_instances) break;
		}

		return list;
	}
}

int list_search(list_t *list, void *element)
{
	assert(list);
	assert(element);

	if (list_is_empty(list))
	{
		return -1;
	}

	{
		int pos = 1;
		
		while (list)
		{
			if (list->data && *((int *)(list->data)) == *((int *)element))
				return pos;

			pos++;
			list = list->next;
		}

		return -1;
	}
}

list_t* list_remove_pos(list_t *list, int pos)
{
	assert(list);
	assert(pos > 0 && pos <= list_size(list));

	if (list_is_empty(list))
	{
		return list;
	}

	if (pos == 1)
	{
		return list_remove_front(list);
	}
	else
	{
		int cur_pos = 1;

		while (list->next && cur_pos < pos - 1)
		{
			cur_pos++;
			list = list->next;
		}

		if (list->next)
		{
			list_t *node_to_rm = list->next;
			free(list->next->data);
			list->next = list->next->next;
			free(node_to_rm);
		}

		return list;
	}
}

int list_is_empty(list_t *list)
{
	assert(list);
	return list->data == NULL;
}

void list_print_as_ints(list_t *list)
{
	assert(list);

	if (list->data)
	{
		printf("%d", *((int*)(list->data)));
		list = list->next;

		while (list && list->data)
		{
			printf(" -> %d", *((int*)(list->data)));
			list = list->next;
		}
	}
	else
	{
		printf("<empty>");
	}
}