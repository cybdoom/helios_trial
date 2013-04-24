/* The structure to represent binary tree's node */
typedef struct binary_tree_t_
{
	void *data;
	struct binary_tree_t_ *parent;
	struct binary_tree_t_ *left_child;
	struct binary_tree_t_ *right_child;
} binary_tree_t;

/* Allocate and initialize a new binary_tree_t handle */
binary_tree_t* btree_init(void);

/* Compare two node-values */
int btree_comparator(void *left_op, void *right_op);

/* Free memory was allocated for the tree */
void btree_dispose(binary_tree_t *root);

/* Insert the given element into the tree following the binary search tree's concept */
void btree_insert(binary_tree_t *root, void *element);

/* Remove the given element from the tree following the binary search tree's concept */
void btree_remove(binary_tree_t *root, void *element);

/* Backtracked output of the tree */
void btree_backtrack_print(binary_tree_t *root);


