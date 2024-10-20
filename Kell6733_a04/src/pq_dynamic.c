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

}

// Destroys a priority queue.
void pq_destroy(pq_dynamic_struct **source) {

	// your code here

}

// Determines if a priority queue is empty.
bool pq_empty(const pq_dynamic_struct *source) {

	// your code here

}

// Determines if the queue is full.
bool pq_full(const pq_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int pq_count(const pq_dynamic_struct *source) {

	// your code here

}

// Inserts an item into a priority queue.
bool pq_insert(pq_dynamic_struct *source, data_type *item) {

	// your code here

}

// Returns a copy of the first of a priority queue.
bool pq_peek(const pq_dynamic_struct *source, data_type *item) {

	// your code here

}

// Returns and removes the item on the first of a priority queue.
bool pq_remove(pq_dynamic_struct *source, data_type *item) {

	// your code here

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
