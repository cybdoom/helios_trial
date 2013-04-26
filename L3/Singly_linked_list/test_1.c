#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	int *x;
	list_t *my_list, *searched_node;

	my_list = list_init();

	assert(list_size(my_list) == 0);
	printf("After initialization: ");
	list_print(my_list);
	
	x = malloc(sizeof(int));
	*x = 1;

	my_list = list_insert_front(my_list, x);
	assert(list_size(my_list) == 1);
	printf("\nAdded front element: ");
	list_print(my_list);

	x = malloc(sizeof(int));
	*x = 3;

	my_list = list_insert_rear(my_list, x);
	assert(list_size(my_list) == 2);
	printf("\nAdded rear element: ");
	list_print(my_list);

	x = malloc(sizeof(int));
	*x = 2;

	my_list = list_insert_after(my_list, x, 1);
	assert(list_size(my_list) == 3);
	printf("\nAdded middle element: ");
	list_print(my_list);

	printf("\nCurrent list length is: %d", list_size(my_list));
	printf("\nSearching for element with value \"2\"... Element was ");
	searched_node = list_search(my_list, x);
	if (searched_node)
	{
		printf("found");
	}
	else
	{
		printf("not found");
	}

	my_list = list_remove_front(my_list);
	assert(list_size(my_list) == 2);
	printf("\nRemoved front element: ");
	list_print(my_list);

	my_list = list_remove_rear(my_list);
	assert(list_size(my_list) == 1);
	printf("\nRemoved rear element: ");
	list_print(my_list);

	my_list = list_remove_pos(my_list, 1);
	assert(list_size(my_list) == 0 && list_is_empty(my_list));
	printf("\nRemoved middle element: ");
	list_print(my_list);

	my_list = list_remove_front(my_list);
	assert(list_size(my_list) == 0 && list_is_empty(my_list));
	printf("\nAttempt to remove node from empty list. The result is: ");
	list_print(my_list);
	printf("\n");	

	list_free(my_list);

	return 0;
}