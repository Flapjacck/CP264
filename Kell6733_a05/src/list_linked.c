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
	// Allocate memory for a new node
	list_node *node = malloc(sizeof *node);
	if (node == NULL) {
		return FALSE;
	}
	// Allocate memory for the item and copy the data
	node->item = malloc(sizeof *item);
	data_copy(node->item, item);
	// Set the new node's next pointer to NULL
	node->next = NULL;

	// If the list is empty, set the front to the new node
	if (source->rear == NULL) {
		source->front = node;
	} else {
		// Otherwise, link the current rear node to the new node
		source->rear->next = node;
	}
	// Update the rear to the new node
	source->rear = node;
	// Increment the count of items in the list
	source->count++;
	return TRUE;
}

// Prepends a item to the front of a list.
BOOLEAN list_prepend(list_linked *source, data_ptr item) {

	// your code here
	// Allocate memory for a new node
	list_node *node = malloc(sizeof *node);
	if (node == NULL) {
		return FALSE;
	}
	// Allocate memory for the item and copy the data
	node->item = malloc(sizeof *item);
	data_copy(node->item, item);
	// Set the new node's next pointer to the current front node
	node->next = source->front;

	// If the list is empty, set the rear to the new node
	if (source->front == NULL) {
		source->rear = node;
	}
	// Update the front to the new node
	source->front = node;
	// Increment the count of items in the list
	source->count++;
	return TRUE;
}

// Returns the number of items in the list.
int list_count(const list_linked *source) {

	// your code here
	return source->count;
}

// Inserts a item to a list at location i.
BOOLEAN list_insert(list_linked *source, data_ptr item, int i) {

	// your code here
	// Check if source or item is NULL
	if (source == NULL || item == NULL) {
		return FALSE;
	}

	// Check if the index is valid
	if (!valid_index(source, i)) {
		return FALSE;
	}

	// If the index is 0, prepend the item
	if (i == 0) {
		return list_prepend(source, item);
	}
	// If the index is equal to the count, append the item
	else if (i == source->count) {
		return list_append(source, item);
	}
	// Otherwise, insert the item at the specified index
	else {
		list_node *prev = NULL;
		list_node *curr = source->front;
		// Traverse the list to find the insertion point
		for (int index = 0; index < i; index++) {
			prev = curr;
			curr = curr->next;
		}

		// Allocate memory for a new node
		list_node *node = malloc(sizeof *node);
		// Check if memory allocation was successful
		if (node == NULL) {
			return FALSE;
		}

		// Initialize the new node's item field
		node->item = malloc(sizeof *item);
		if (node->item == NULL) {
			free(node);
			return FALSE;
		}

		// Copy the item data to the new node
		data_copy(node->item, item);
		// Link the new node to the current node
		node->next = curr;
		// Link the previous node to the new node
		prev->next = node;
		// Increment the count of items in the list
		source->count++;
		// Return TRUE to indicate success
		return TRUE;
	}
}

// Returns a copy of the front of a list.
BOOLEAN list_peek(const list_linked *source, data_ptr item) {

	// your code here
	// Check if the list is empty
	if (list_empty(source)) {
		return FALSE;
	}
	// Copy the item data from the front node to the provided item
	data_copy(item, source->front->item);
	// Return TRUE to indicate success
	return TRUE;
}

// Returns a copy of the item matching key in a list.
BOOLEAN list_key_find(const list_linked *source, const data_ptr key,
		data_ptr item) {

	// your code here
	list_node *prev = NULL;
	list_node *curr = NULL;
	// Perform a linear search to find the node containing the key
	int index = linear_search(source, key, &prev, &curr);
	// If the key is not found, return FALSE
	if (index == -1) {
		return FALSE;
	}
	// Copy the item data from the found node to the provided item
	data_copy(item, curr->item);
	// Return TRUE to indicate success
	return TRUE;
}

// Removes and returns the item matching key from the list.
BOOLEAN list_key_remove(list_linked *source, const data_ptr key, data_ptr item) {

	// your code here
	list_node *prev = NULL;
	list_node *curr = NULL;
	// Perform a linear search to find the node containing the key
	int index = linear_search(source, key, &prev, &curr);
	// If the key is not found, return FALSE
	if (index == -1) {
		return FALSE;
	}

	// If the node to be removed is the front node
	if (prev == NULL) {
		source->front = curr->next;
	} else {
		// Otherwise, link the previous node to the next node
		prev->next = curr->next;
	}

	// If the node to be removed is the rear node
	if (curr == source->rear) {
		source->rear = prev;
	}

	// Copy the item data from the found node to the provided item
	data_copy(item, curr->item);
	// Free the memory allocated for the node
	free_node(&curr);
	// Decrement the count of items in the list
	source->count--;
	// Return TRUE to indicate success
	return TRUE;
}

BOOLEAN list_remove_front(list_linked *source, data_ptr item) {

	// your code here
	// Check if the list is empty
	if (list_empty(source)) {
		return FALSE;
	}

	// Get the front node
	list_node *node = source->front;
	// Update the front pointer to the next node
	source->front = node->next;
	// If the list becomes empty, update the rear pointer to NULL
	if (source->front == NULL) {
		source->rear = NULL;
	}

	// Copy the item data from the front node to the provided item
	data_copy(item, node->item);
	// Free the memory allocated for the node
	free_node(&node);
	// Decrement the count of items in the list
	source->count--;
	// Return TRUE to indicate success
	return TRUE;
}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_linked *source, const data_ptr key) {

	// your code here
	list_node *prev = NULL;
	list_node *curr = NULL;
	// Perform a linear search to find the node containing the key
	return linear_search(source, key, &prev, &curr);
}

// Determines if key is in a list.
BOOLEAN list_key_contains(const list_linked *source, const data_ptr key) {

	// your code here
	return list_key_index(source, key) != -1;
}

// Determines number of times key appears in list.
int list_key_count(const list_linked *source, const data_ptr key) {

	// your code here
	int count = 0;
	// Start from the front of the list
	list_node *curr = source->front;
	// Traverse the list
	while (curr != NULL) {
		// Compare the current node's item with the key
		if (data_compare(curr->item, key) == 0) {
			count++;
		}
		// Move to the next node
		curr = curr->next;
	}
	// Return the count of occurrences
	return count;
}

// Removes and returns the item at index i from a list.
BOOLEAN list_index_remove(list_linked *source, data_ptr item, int i) {

	// your code here
	// Check if the index is valid
	if (!valid_index(source, i)) {
		return FALSE;
	}

	list_node *prev = NULL;
	list_node *curr = source->front;
	// Traverse the list to find the node at the specified index
	for (int index = 0; index < i; index++) {
		prev = curr;
		curr = curr->next;
	}

	// If the node to be removed is the front node
	if (prev == NULL) {
		source->front = curr->next;
	} else {
		// Otherwise, link the previous node to the next node
		prev->next = curr->next;
	}

	// If the node to be removed is the rear node
	if (curr == source->rear) {
		source->rear = prev;
	}

	// Copy the item data from the found node to the provided item
	data_copy(item, curr->item);
	// Free the memory allocated for the node
	free_node(&curr);
	// Decrement the count of items in the list
	source->count--;
	// Return TRUE to indicate success
	return TRUE;
}

// Finds the maximum item in a list.
BOOLEAN list_max(const list_linked *source, data_ptr item) {

	// your code here
	// Check if the list is empty
	if (list_empty(source)) {
		return FALSE;
	}

	// Initialize the current node to the front of the list
	list_node *curr = source->front;
	// Copy the first item to the provided item
	data_copy(item, curr->item);
	// Move to the next node
	curr = curr->next;

	// Traverse the list to find the maximum item
	while (curr != NULL) {
		// Compare the current node's item with the maximum item found so far
		if (data_compare(curr->item, item) > 0) {
			// Update the maximum item if the current item is larger
			data_copy(item, curr->item);
		}
		// Move to the next node
		curr = curr->next;
	}
	// Return TRUE to indicate success
	return TRUE;
}

// Finds the minimum item in a list.
BOOLEAN list_min(const list_linked *source, data_ptr item) {

	// your code here
	// Check if the list is empty
	if (list_empty(source)) {
		return FALSE;
	}

	// Initialize the current node to the front of the list
	list_node *curr = source->front;
	// Copy the first item to the provided item
	data_copy(item, curr->item);
	// Move to the next node
	curr = curr->next;

	// Traverse the list to find the minimum item
	while (curr != NULL) {
		// Compare the current node's item with the minimum item found so far
		if (data_compare(curr->item, item) < 0) {
			// Update the minimum item if the current item is smaller
			data_copy(item, curr->item);
		}
		// Move to the next node
		curr = curr->next;
	}
	// Return TRUE to indicate success
	return TRUE;
}

// Removes all duplicate items from a list.
void list_clean(list_linked *source) {

	// your code here
	// Check if the source is NULL
	if (source == NULL) {
		return;
	}

	list_node *curr = source->front;
	while (curr != NULL) {
		list_node *runner = curr;
		while (runner->next != NULL) {
			if (data_compare(curr->item, runner->next->item) == 0) {
				// Duplicate found, remove it
				list_node *dup = runner->next;
				runner->next = runner->next->next;
				// Free the duplicate node
				free_node(&dup);
				source->count--;
			} else {
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
}

// Compares two lists for equality.
BOOLEAN list_equal(const list_linked *target, const list_linked *source) {

	// your code here
	// Check if the counts of the two lists are different
	if (target->count != source->count) {
		return FALSE;
	}

	// Initialize the current nodes to the front of each list
	list_node *curr1 = target->front;
	list_node *curr2 = source->front;

	// Traverse both lists
	while (curr1 != NULL && curr2 != NULL) {
		// Compare the items of the current nodes
		if (data_compare(curr1->item, curr2->item) != 0) {
			return FALSE;
		}
		// Move to the next nodes
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	// Return TRUE if all items are equal
	return TRUE;
}

void list_combine(list_linked *target, list_linked *source1,
		list_linked *source2) {

	// your code here
	append_nodes(target, source1);
	append_nodes(target, source2);
}

void list_split_alt(list_linked *target1, list_linked *target2,
		list_linked *source) {

	// your code here
	int index = 0;
	// Start from the front of the source list
	list_node *curr = source->front;
	while (curr != NULL) {
		list_node *next = curr->next;
		// Disconnect the current node from the source list
		curr->next = NULL;
		if (index % 2 == 0) {
			// Add the node to the end of target1
			if (target1->rear == NULL) {
				target1->front = curr;
			} else {
				target1->rear->next = curr;
			}
			target1->rear = curr;
			target1->count++;
		} else {
			// Add the node to the end of target2
			if (target2->rear == NULL) {
				target2->front = curr;
			} else {
				target2->rear->next = curr;
			}
			target2->rear = curr;
			target2->count++;
		}
		// Move to the next node
		curr = next;
		index++;
	}
	// Clear the source list
	source->front = NULL;
	source->rear = NULL;
	source->count = 0;
}

void list_split(list_linked *target1, list_linked *target2, list_linked *source) {

	// your code here
	// Calculate the midpoint of the source list
	int mid = source->count / 2;
	// Start from the front of the source list
	list_node *curr = source->front;
	// Append the first half of the source list to target1
	for (int i = 0; i < mid; i++) {
		list_append(target1, curr->item);
		curr = curr->next;
	}
	// Append the second half of the source list to target2
	while (curr != NULL) {
		list_append(target2, curr->item);
		curr = curr->next;
	}
	// Clean the source list
	list_clean(source);
}

void list_split_key(list_linked *target1, list_linked *target2,
		list_linked *source, data_ptr key) {

	// your code here
	// Initialize the current node to the front of the source list
	list_node *curr = source->front;
	// Traverse the source list
	while (curr != NULL) {
		// Compare the current node's item with the key
		if (data_compare(curr->item, key) < 0) {
			// Append the item to target1 if it is less than the key
			list_append(target1, curr->item);
		} else {
			// Append the item to target2 if it is greater than or equal to the key
			list_append(target2, curr->item);
		}
		// Move to the next node
		curr = curr->next;
	}
	// Clean the source list
	list_clean(source);

}

list_linked* list_copy(const list_linked *source) {

	// your code here
	// Initialize a new list to store the copy
	list_linked *copy = list_initialize();
	// Start from the front of the source list
	list_node *curr = source->front;
	// Traverse the source list
	while (curr != NULL) {
		// Append the current item to the copy list
		list_append(copy, curr->item);
		// Move to the next node
		curr = curr->next;
	}
	// Return the copied list
	return copy;
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
