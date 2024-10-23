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
	// Iterate through each item in the list
	for (int i = 0; i < source->count; i++) {
		// Compare the current item with the key
		if (data_compare(&(source->items[i]), key) == 0) {
			// If a match is found, return the index
			return i;
		}
	}
	// If no match is found, return -1
	return -1;

}

// Functions

// Initializes a list.
void list_initialize(list_dynamic_struct **source, int capacity) {

	// your code here
	*source = (list_dynamic_struct*) malloc(sizeof(list_dynamic_struct));
	(*source)->capacity = capacity;
	(*source)->count = 0;
	(*source)->items = (data_type*) malloc(capacity * sizeof(data_type));
}

// Destroys a list.
void list_destroy(list_dynamic_struct **source) {

	// your code here
	free((*source)->items);
	free(*source);
	*source = NULL;

}

// Determines if a list is empty.
bool list_empty(const list_dynamic_struct *source) {

	// your code here
	return source->count == 0;

}

// Determines if the list is full.
bool list_full(const list_dynamic_struct *source) {
	return false;
}

// Appends a item to the end of a list.
bool list_append(list_dynamic_struct *source, data_type *item) {

	// your code here
	if (list_full(source)) {
		return false;
	}
	source->items[source->count++] = *item;
	return true;

}

// Returns the number of items in the list.
int list_count(const list_dynamic_struct *source) {

	// your code here
	return source->count;

}

// Inserts a item to a list at location i.
bool list_insert(list_dynamic_struct *source, data_type *item, int i) {

	// your code here
	if (list_full(source) || !valid_index(source, i)) {
		return false;
	}
	for (int j = source->count; j > i; j--) {
		source->items[j] = source->items[j - 1];
	}
	source->items[i] = *item;
	source->count++;
	return true;

}

// Returns a copy of the front of a list.
bool list_peek(const list_dynamic_struct *source, data_type *item) {

	// your code here
	if (list_empty(source)) {
		return false;
	}
	*item = source->items[0];
	return true;

}

// Returns a copy of the item matching key in a list.
bool list_key_find(const list_dynamic_struct *source, const data_type *key,
		data_type *item) {

	// your code here
	int index = list_linear_search(source, key);
	if (index == -1) {
		return false;
	}
	*item = source->items[index];
	return true;

}

// Removes and returns the item matching key from the list.
bool list_key_remove(list_dynamic_struct *source, const data_type *key,
		data_type *item) {

	// your code here
	int index = list_linear_search(source, key);
	if (index == -1) {
		return false;
	}
	*item = source->items[index];
	for (int i = index; i < source->count - 1; i++) {
		source->items[i] = source->items[i + 1];
	}
	source->count--;
	return true;

}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_dynamic_struct *source, const data_type *key) {

	// your code here
	return list_linear_search(source, key);
}

// Determines if key is in a list.
bool list_key_contains(const list_dynamic_struct *source, const data_type *key) {

	// your code here
	return list_linear_search(source, key) != -1;

}

// Determines number of times key appears in list.
int list_key_count(const list_dynamic_struct *source, const data_type *key) {

	// your code here
	int count = 0;
	for (int i = 0; i < source->count; i++) {
		if (data_compare(&(source->items[i]), key) == 0) {
			count++;
		}
	}
	return count;

}

// Removes and returns the item at index i from a list.
bool list_index_remove(list_dynamic_struct *source, data_type *item, int i) {

	// your code here
	if (!valid_index(source, i)) {
		return false;
	}
	*item = source->items[i];
	for (int j = i; j < source->count - 1; j++) {
		source->items[j] = source->items[j + 1];
	}
	source->count--;
	return true;

}

// Finds the maximum item in a list.
bool list_max(const list_dynamic_struct *source, data_type *item) {

	// your code here
	if (list_empty(source)) {
		return false;
	}
	*item = source->items[0];
	for (int i = 1; i < source->count; i++) {
		if (data_compare(&(source->items[i]), item) > 0) {
			*item = source->items[i];
		}
	}
	return true;

}

// Finds the minimum item in a list.
bool list_min(const list_dynamic_struct *source, data_type *item) {

	// your code here
	if (list_empty(source)) {
		return false;
	}
	*item = source->items[0];
	for (int i = 1; i < source->count; i++) {
		if (data_compare(&(source->items[i]), item) < 0) {
			*item = source->items[i];
		}
	}
	return true;

}

// Removes all duplicate items from a list.
void list_clean(list_dynamic_struct *source) {

	// your code here
	for (int i = 0; i < source->count; i++) {
		for (int j = i + 1; j < source->count; j++) {
			if (data_compare(&(source->items[i]), &(source->items[j])) == 0) {
				for (int k = j; k < source->count - 1; k++) {
					source->items[k] = source->items[k + 1];
				}
				source->count--;
				j--;
			}
		}
	}
}

// Compares two lists for equality.
bool list_equal(const list_dynamic_struct *target,
		const list_dynamic_struct *source) {

	// your code here
	if (target->count != source->count) {
		return false;
	}
	for (int i = 0; i < source->count; i++) {
		if (data_compare(&(target->items[i]), &(source->items[i])) != 0) {
			return false;
		}
	}
	return true;

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
