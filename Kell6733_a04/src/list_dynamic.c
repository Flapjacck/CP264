/**
 * -------------------------------------
 * @file  list_dynamic.c
 * Dynamic List Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "list_dynamic.h"

// Private helper functions

/**
 * Determines if an index is valid.
 *
 * @param list - pointer to a list.
 * @param i - index to check
 * @return - true if i is a valid index, false otherwise
 */
static bool valid_index(const list_dynamic_struct *source, int i) {
	return ((i >= 0) && (i <= source->count));
}

/**
 * Performs a linear search on source->items for key.
 *
 * @param list - pointer to a list.
 * @param key - key of item to look for in list.
 * @return - index of location of key in list, -1 if key not in list.
 */
static int list_linear_search(const list_dynamic_struct *source,
		const data_type *key) {

	// your code here

}

// Functions

// Initializes a list.
void list_initialize(list_dynamic_struct **source, int capacity) {

	// your code here

}

// Destroys a list.
void list_destroy(list_dynamic_struct **source) {

	// your code here

}

// Determines if a list is empty.
bool list_empty(const list_dynamic_struct *source) {

	// your code here

}

// Determines if the list is full.
bool list_full(const list_dynamic_struct *source) {
	return false;
}

// Appends a item to the end of a list.
bool list_append(list_dynamic_struct *source, data_type *item) {

	// your code here

}

// Returns the number of items in the list.
int list_count(const list_dynamic_struct *source) {

	// your code here

}

// Inserts a item to a list at location i.
bool list_insert(list_dynamic_struct *source, data_type *item, int i) {

	// your code here

}

// Returns a copy of the front of a list.
bool list_peek(const list_dynamic_struct *source, data_type *item) {

	// your code here

}

// Returns a copy of the item matching key in a list.
bool list_key_find(const list_dynamic_struct *source, const data_type *key,
		data_type *item) {

	// your code here

}

// Removes and returns the item matching key from the list.
bool list_key_remove(list_dynamic_struct *source, const data_type *key,
		data_type *item) {

	// your code here

}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_dynamic_struct *source, const data_type *key) {

	// your code here

}

// Determines if key is in a list.
bool list_key_contains(const list_dynamic_struct *source, const data_type *key) {

	// your code here

}

// Determines number of times key appears in list.
int list_key_count(const list_dynamic_struct *source, const data_type *key) {

	// your code here

}

// Removes and returns the item at index i from a list.
bool list_index_remove(list_dynamic_struct *source, data_type *item, int i) {

	// your code here

}

// Finds the maximum item in a list.
bool list_max(const list_dynamic_struct *source, data_type *item) {

	// your code here

}

// Finds the minimum item in a list.
bool list_min(const list_dynamic_struct *source, data_type *item) {

	// your code here

}

// Removes all duplicate items from a list.
void list_clean(list_dynamic_struct *source) {

	// your code here

}

// Compares two lists for equality.
bool list_equal(const list_dynamic_struct *target,
		const list_dynamic_struct *source) {

	// your code here

}

// Prints the items in a list from front to rear.
void list_print(const list_dynamic_struct *source) {
	// Walk through stack from top to bottom using indexes.
	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[i]));
		printf("\n");
	}
	return;
}
