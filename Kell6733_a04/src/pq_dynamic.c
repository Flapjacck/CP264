/**
 * -------------------------------------
 * @file  pq_dynamic.c
 * Dynamic Priority Queue Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "pq_dynamic.h"

// Functions

// Initializes a priority queue.
void pq_initialize(pq_dynamic_struct **source, int capacity) {

	// your code here
	*source = (pq_dynamic_struct*) malloc(sizeof(pq_dynamic_struct));
	(*source)->capacity = capacity;
	(*source)->count = 0;
	(*source)->first = -1;
	(*source)->items = (data_type*) malloc(capacity * sizeof(data_type));

}

// Destroys a priority queue.
void pq_destroy(pq_dynamic_struct **source) {

	// your code here
	free((*source)->items);
	free(*source);
	*source = NULL;

}

// Determines if a priority queue is empty.
bool pq_empty(const pq_dynamic_struct *source) {

	// your code here
	return source->count == 0;

}

// Determines if the queue is full.
bool pq_full(const pq_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int pq_count(const pq_dynamic_struct *source) {

	// your code here
	return source->count;

}

// Inserts an item into a priority queue.
bool pq_insert(pq_dynamic_struct *source, data_type *item) {

	// your code here
	if (pq_full(source)) {
		return false;
	}
	source->items[source->count++] = *item;
	// Update the first index if necessary
	if (source->first == -1 || *item < source->items[source->first]) {
		source->first = source->count - 1;
	}
	return true;

}

// Returns a copy of the first of a priority queue.
bool pq_peek(const pq_dynamic_struct *source, data_type *item) {

	// your code here
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	return true;

}

// Returns and removes the item on the first of a priority queue.
bool pq_remove(pq_dynamic_struct *source, data_type *item) {

	// your code here
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	// Shift items to fill the gap
	for (int i = source->first; i < source->count - 1; i++) {
		source->items[i] = source->items[i + 1];
	}
	source->count--;
	// Update the first index
	if (source->count == 0) {
		source->first = -1;
	} else {
		source->first = 0;
		for (int i = 1; i < source->count; i++) {
			if (source->items[i] < source->items[source->first]) {
				source->first = i;
			}
		}
	}
	return true;

}

// Prints the items in a priority queue from first to rear.
void pq_print(const pq_dynamic_struct *source) {
	// Walk through stack from top to bottom using indexes.
	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[i]));
		printf("\n");
	}
	return;
}
