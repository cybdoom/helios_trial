#include <stddef.h>

/* The structure to represent singly linked list's node */
typedef struct list_t_
{
	void *data;
	struct list_t_ *next;
} list_t;

/* Allocate and initialize a new list_t handle */
list_t *list_init(void);

/* Insert an item in front of the list. Returns the pointer to the new head*/
list_t* list_insert_front(list_t *list, void *element);

/* Insert an item at the given position of the list. Returns the pointer to the new head */
list_t* list_insert_after(list_t *list, void *element, int pos);

/* Insert an item in the end of the list. Returns the pointer to the new head */
list_t* list_insert_rear(list_t *list, void *element);

/* Remove the front element of the list. Returns the pointer to the new head */
list_t* list_remove_front(list_t *list);

/* Remove the specified element of the list. Returns the pointer to the new head */
list_t* list_remove_any(list_t *list, void *element, int remove_all_instances);

/* Remove the element on specified position. Returns the pointer to the new head */
list_t* list_remove_pos(list_t *list, int pos);

/* Remove the end element of the list. Returns the pointer to the new head */
list_t* list_remove_rear(list_t *list);

/* Retrieve the number of elements in the list */
size_t list_size(list_t *list);

/* Search for position of specified element in target list */
int list_search(list_t *list, void *element);

/* Free memory was allocated for the list */
void list_free(list_t *list);

/* Returns if the list is empty */
int list_is_empty(list_t *list);

/* Prints the list */
void list_print_as_ints(list_t *list);