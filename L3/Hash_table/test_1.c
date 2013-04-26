#include "hash_table.h"

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	hash_table_t *my_table = htable_init(128);
	long int i;

	/* Turn off buffering of the standart output stream */ 
	setvbuf(stdout, NULL, _IONBF, 0);

	/* Fill our table with 100000 trash elements */
	printf("Filling tree with numbers from 1 to 100000 ... ");
	i = 5;
	for (i = 0; i < 100000; i++)
	{
		int *x = malloc(sizeof(int));
		*x = i;
		htable_insert(my_table, x);
	}
	printf("Done\n");

	/* Searchprintf("Disposing hash-table ... "); our table for 100000 times. Each time we look for different values */
	printf("Searching for 100000 times for digits from 1 to 100000 ... ");
	for (i = 100000; i >=0; i--)
	{
		void* node = htable_search(my_table, &i);
	}
	printf("Done\n");

	printf("Disposing hash-table ... ");
	htable_dispose(my_table);
	printf("Done\n");

	return 0;
}