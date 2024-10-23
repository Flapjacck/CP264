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
	// Allocate memory for the queue structure
	*source = (queue_dynamic_struct*) malloc(sizeof(queue_dynamic_struct));
	// Set the initial capacity
	(*source)->capacity = capacity;
	// Initialize count, front, and rear
	(*source)->count = 0;
	(*source)->front = 0;
	(*source)->rear = -1;
	// Allocate memory for the items array
	(*source)->items = (data_type*) malloc(capacity * sizeof(data_type));

}

// Destroys a queue.
void queue_destroy(queue_dynamic_struct **source) {

	// your code here
	// Free the memory allocated for the items array
	free((*source)->items);
	// Free the memory allocated for the queue structure
	free(*source);
	// Set the source pointer to NULL
	*source = NULL;

}

// Determines if a queue is empty.
bool queue_empty(const queue_dynamic_struct *source) {

	// your code here
	// Return true if count is 0, otherwise false
	return source->count == 0;

}

// Determines if the queue is full.
bool queue_full(const queue_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int queue_count(const queue_dynamic_struct *source) {

	// your code here
	// Return the count of items in the queue
	return source->count;

}

// Inserts an item into a queue.
bool queue_insert(queue_dynamic_struct *source, data_type *item) {

	// your code here
	// Check if the queue is full
	if (queue_full(source)) {
		return false;
	}
	// Update the rear index in a circular manner
	source->rear = (source->rear + 1) % source->capacity;
	// Insert the item at the rear
	source->items[source->rear] = *item;
	// Increment the count
	source->count++;
	return true;
}

// Returns a copy of the front of a queue.
bool queue_peek(const queue_dynamic_struct *source, data_type *item) {

	// your code here
	// Check if the queue is empty
	if (queue_empty(source)) {
		return false;
	}
	// Copy the item at the front to the provided item pointer
	*item = source->items[source->front];
	return true;

}

// Returns and removes the item on the front of a queue.
bool queue_remove(queue_dynamic_struct *source, data_type *item) {

	// your code here
	// Check if the queue is empty
	if (queue_empty(source)) {
		return false;
	}
	// Copy the item at the front to the provided item pointer
	*item = source->items[source->front];
	// Update the front index in a circular manner
	source->front = (source->front + 1) % source->capacity;
	// Decrement the count
	source->count--;
	return true;

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
