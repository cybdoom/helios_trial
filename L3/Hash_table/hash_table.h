typedef struct hash_table_t_
{
	int size;
	void **rows;
} hash_table_t;

/* Initialize the new instance of hash-table. Returns new handle */
hash_table_t* htable_init(int size);

/* Insert the given element into hash-table */
void htable_insert(hash_table_t *table, void *element);

/* Free memory occupied by the given hash-table instance */
void htable_dispose(hash_table_t *table);

/* Remove the given element from hash-table */
void htable_remove(hash_table_t *table, void *element);

/* Returns hash-value for the given element */
int hash_func(hash_table_t *table, void *element);

/* Search for the given element */
void* htable_search(hash_table_t *table, void *element);

/* Print the given hash-table */
void htable_print(hash_table_t *table);
