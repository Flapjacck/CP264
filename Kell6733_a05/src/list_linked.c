/**
 * -------------------------------------
 * @file  list_linked.c
 * Linked List Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-11-01
 *
 * -------------------------------------
 */
#include "list_linked.h"

//==================================================================================
// Private helper functions - use in public functions

/**
 * Determines if an index in source is valid.
 *
 * @param source - pointer to source
 * @param i - index to check
 * @return - TRUE if i is a valid index, FALSE otherwise
 */
static BOOLEAN valid_index(const list_linked *source, int i) {
	return ((i >= 0) && (i <= source->count));
}

/**
 * Performs a linear search on source for key.
 * Updates prev and curr pointers.
 *
 * @param source - pointer to source
 * @param key - key to search for
 * @param prev - pointer to node previous to node containing key
 * @param curr - pointer to node containing key
 * @return - -1 if key is not found, index of node if found
 */
static int linear_search(const list_linked *source, const data_ptr key,
		list_node **prev, list_node **curr) {

	// your code here
	int index = 0;
	*prev = NULL;
	*curr = source->front;

	while (*curr != NULL) {
		//check if current item's data matches the key
		if (data_compare((*curr)->item, key) == 0) {
			return index;
		}
		//move to the next item in the list
		*prev = *curr;
		*curr = (*curr)->next;
		index++;
	}
	//return -1 if key is not found
	return -1;
}

/**
 * Frees list_node memory.
 *
 * @param node - node to free
 */
static void free_node(list_node **node) {
	// Free the removed node.
	data_free(&(*node)->item);
	free(*node);
	*node = NULL;
	return;
}

/**
 * Moves front node of source to target. Does nothing if source is empty.
 *
 * @param target - pointer to target
 * @param source - pointer to source
 */
static void move_front_to_rear(list_linked *target, list_linked *source) {

	// your code here
	//return if the source list is empty
	if (source->front == NULL) {
		return;
	}

	// remove the front node from the source list
	list_node *node = source->front;
	source->front = source->front->next;
	//update the rear pointer if the source list becomes empty
	if (source->front == NULL) {
		source->rear = NULL;
	}
	node->next = NULL;

	//add the node to the rear of the target list
	if (target->rear == NULL) {
		target->front = node;
	} else {
		target->rear->next = node;
	}
	target->rear = node;
	target->count++;
	source->count--;
}

/**
 * Appends all nodes of source to rear of target. source is empty when finished.
 * MUST NOT USE LOOP!
 *
 * @param target - pointer to target
 * @param source - pointer to source
 */
static void append_nodes(list_linked *target, list_linked *source) {

	// your code here
	//return if the source list is empty
	if (source->front == NULL) {
		return;
	}

	// append the source list to the target list
	if (target->rear == NULL) {
		target->front = source->front;
	} else {
		target->rear->next = source->front;
	}
	target->rear = source->rear;
	target->count += source->count;

	//reset the source list
	source->front = NULL;
	source->rear = NULL;
	source->count = 0;
}

//==================================================================================
// Functions

// Initializes a list.
list_linked* list_initialize() {
	list_linked *source = malloc(sizeof *source);
	source->front = NULL;
	source->rear = NULL;
	source->count = 0;
	return source;
}

// Destroys a list.
void list_free(list_linked **source) {

	// your code here
	//initialize the current node pointer to the front of the list
	list_node *curr = (*source)->front;
	while (curr != NULL) {
		//store the next node
		list_node *next = curr->next;
		//free the current node
		free_node(&curr);
		//move to the next node
		curr = next;
	}
	//free the list structure and set the source pointer to NULL
	free(*source);
	*source = NULL;
}

// Determines if a list is empty.
BOOLEAN list_empty(const list_linked *source) {

	// your code here
	return source->count == 0;
}

// Determines if the list is full.
BOOLEAN list_full(const list_linked *source) {
	return FALSE;
}

// Appends a item to the end of a list.
BOOLEAN list_append(list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Prepends a item to the front of a list.
BOOLEAN list_prepend(list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Returns the number of items in the list.
int list_count(const list_linked *source) {

	// your code here

	return 0;
}

// Inserts a item to a list at location i.
BOOLEAN list_insert(list_linked *source, data_ptr item, int i) {

	// your code here

	return FALSE;
}

// Returns a copy of the front of a list.
BOOLEAN list_peek(const list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Returns a copy of the item matching key in a list.
BOOLEAN list_key_find(const list_linked *source, const data_ptr key,
		data_ptr item) {

	// your code here

	return FALSE;
}

// Removes and returns the item matching key from the list.
BOOLEAN list_key_remove(list_linked *source, const data_ptr key, data_ptr item) {

	// your code here

	return FALSE;
}

BOOLEAN list_remove_front(list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_linked *source, const data_ptr key) {

	// your code here

	return -1;
}

// Determines if key is in a list.
BOOLEAN list_key_contains(const list_linked *source, const data_ptr key) {

	// your code here

	return FALSE;
}

// Determines number of times key appears in list.
int list_key_count(const list_linked *source, const data_ptr key) {

	// your code here

	return 0;
}

// Removes and returns the item at index i from a list.
BOOLEAN list_index_remove(list_linked *source, data_ptr item, int i) {

	// your code here

	return FALSE;
}

// Finds the maximum item in a list.
BOOLEAN list_max(const list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Finds the minimum item in a list.
BOOLEAN list_min(const list_linked *source, data_ptr item) {

	// your code here

	return FALSE;
}

// Removes all duplicate items from a list.
void list_clean(list_linked *source) {

	// your code here

	return;
}

// Compares two lists for equality.
BOOLEAN list_equal(const list_linked *target, const list_linked *source) {

	// your code here

	return FALSE;
}

void list_combine(list_linked *target, list_linked *source1,
		list_linked *source2) {

	// your code here

	return;
}

void list_split_alt(list_linked *target1, list_linked *target2,
		list_linked *source) {

	// your code here

	return;
}

void list_split(list_linked *target1, list_linked *target2, list_linked *source) {

	// your code here

	return;
}

void list_split_key(list_linked *target1, list_linked *target2,
		list_linked *source, data_ptr key) {

	// your code here

	return;

}

list_linked* list_copy(const list_linked *source) {

	// your code here

	return NULL;
}

// Prints the items in a list from front to rear.
void list_print(const list_linked *source) {
	char string[DATA_STRING_SIZE];
	list_node *curr = source->front;

	while (curr != NULL) {
		printf("%s\n", data_string(string, sizeof string, curr->item));
		curr = curr->next;
	}
	return;
}