#include "singly_linked_list.h"

int main(void)
{
	list_t *my_list = list_init();
	int *x = malloc(sizeof(int));
	*x = 3;

	list_insert_front(my_list, x);

	list_free(my_list);

	return 0;
}