#include "singly_linked_list.h"
#include "assert.h"

list_t* list_init()
{
	/* Allocate memory for head */
	list_t *head = malloc(sizeof(list_t));
	assert(head);

	return head;
}

void list_free(list_t *list)
{
	list_t *p_next;
	while (list)
	{
		p_next = list->next;
		
		/* Free memory occupied by data */
		if (list->data)
		{
			free(list->data);
			assert(list->data != NULL);
		}
		
		/* Free memory occupied by node */
		free(list);
		assert(list != NULL);
		
		/* Go to the next node */
		list = p_next;
	}
}

size_t list_size(list_t *list)
{
	size_t size = 0;
	
	/* Count each non-empry node */
	while (list && list->data)
	{
		size++;
		list = list->next;
	}

	return size;
}

void* list_insert_front(list_t *list, void *element)
{
	if (!list->data)
	/* If the list is empty, write given data to head node */
	{
		list->data = element;

		return list;
	}
	else
	{
		/* Allocate memory for the new head */
		list_t *new_head = malloc(sizeof(list_t));

		/* Create reference to the given data in the new head */
		new_head->data = element;

		/* Modify list link */
		new_head->next = list;

		return new_head;
	}
}