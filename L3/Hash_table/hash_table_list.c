#include "hash_table.h"
#include "../Singly_linked_list/singly_linked_list.h"

#include <stdlib.h>
#include <stdio.h>

hash_table_t* htable_init(int size)
{
	hash_table_t *new_handle = malloc(sizeof(hash_table_t));
	int i;
	
	new_handle->rows = malloc(sizeof(list_t*) * size);
	
	for (i = 0; i < size; i++)
	{
		*(new_handle->rows + i) = list_init();
	}

	new_handle->size = size;

	return new_handle;
}

void htable_insert(hash_table_t *table, void *element)
{
	int hash_value = hash_func(table, element);

	list_insert_front(*((list_t **)(table->rows + hash_value)), element);
}

void htable_remove(hash_table_t *table, void *element)
{
	int hash_value = hash_func(table, element);

	list_remove_any(*((list_t **)(table->rows + hash_value)), element, 0);
}

int hash_func(hash_table_t *table, void *element)
{
	int element_as_int = *((int *)(element));
	return element_as_int % table->size;
}

void htable_dispose(hash_table_t *table)
{
	int i;
	for (i = 0; i < table->size; ++i)
	{
		list_free(*((list_t **)(table->rows + i)));
	}

	free(table->rows);
	free(table);
}

void htable_print(hash_table_t *table)
{
	int i;

	printf("\n===TABLE===\n");
	for (i = 0; i < table->size; i++)
	{
		printf("%d: -----> ", i);
		list_print(*((list_t **)(table->rows + i)));
		printf("\n");
	}
}

void* htable_search(hash_table_t *table, void *element)
{
	int hash_value = hash_func(table, element);

	if (hash_value > table->size)
		return NULL;

	return list_search(*((list_t **)(table->rows) + hash_value), element);
}