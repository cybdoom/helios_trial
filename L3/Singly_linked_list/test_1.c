#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	list_t *my_list = list_init();
	assert(list_size(my_list) == 0);
	int *x = malloc(sizeof(int));
	*x = 1;

	my_list = list_insert_front(my_list, x);
	assert(list_size(my_list) == 1);
	list_print_as_ints(my_list);
	printf("\n");

	x = malloc(sizeof(int));
	*x = 2;

	my_list = list_insert_after(my_list, x, 1);
	assert(list_size(my_list) == 2);
	list_print_as_ints(my_list);
	printf("\n");

	x = malloc(sizeof(int));
	*x = 3;

	my_list = list_insert_rear(my_list, x);
	assert(list_size(my_list) == 3);
	list_print_as_ints(my_list);
	printf("\n");

	x = malloc(sizeof(int));
	*x = 3;

	my_list = list_insert_after(my_list, x, 1);
	assert(list_size(my_list) == 4);
	list_print_as_ints(my_list);
	printf("\n");

	{
		int *etalon = malloc(sizeof(int));
		*etalon = 3;
		my_list = list_remove_any(my_list, etalon, 1);
		free(etalon);
		list_print_as_ints(my_list);
		printf("\n");
	}

	list_free(my_list);
	assert(my_list);

	return 0;
}