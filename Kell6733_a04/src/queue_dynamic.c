/**
 * -------------------------------------
 * @file  queue_dynamic.c
 * Dynamic Queue Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "queue_dynamic.h"

// Functions

// Initializes a queue.
void queue_initialize(queue_dynamic_struct **source, int capacity) {

	// your code here

}

// Destroys a queue.
void queue_destroy(queue_dynamic_struct **source) {

	// your code here

}

// Determines if a queue is empty.
bool queue_empty(const queue_dynamic_struct *source) {

	// your code here

}

// Determines if the queue is full.
bool queue_full(const queue_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int queue_count(const queue_dynamic_struct *source) {

	// your code here

}

// Inserts an item into a queue.
bool queue_insert(queue_dynamic_struct *source, data_type *item) {

	// your code here

	return true;
}

// Returns a copy of the front of a queue.
bool queue_peek(const queue_dynamic_struct *source, data_type *item) {

	// your code here

}

// Returns and removes the item on the front of a queue.
bool queue_remove(queue_dynamic_struct *source, data_type *item) {

	// your code here

}

void queue_print(const queue_dynamic_struct *source) {
	// Walk through queue from front to rear using indexes.
	int temp = source->front;

	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[temp]));
		printf("\n");
		temp = (temp + 1) % source->capacity;
	}
	return;
}
