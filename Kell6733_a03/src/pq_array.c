/**
 * -------------------------------------
 * @file  pq_array.c
 * pq_array Source Code File
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "pq_array.h"

// Functions

// your code here (include all stubs!)

// Initializes a priority queue
void pq_initialize(pq_struct *source) {
	source->capacity = PQ_INIT; // Set initial capacity
	source->count = 0;          // Initialize count of items to 0
	source->first = 0; // Initialize the index of the highest priority item to 0
}

// Checks if the priority queue is empty
bool pq_empty(const pq_struct *source) {
	return source->count == 0;  // Returns true if the count of items is 0
}

// Checks if the priority queue is full
bool pq_full(const pq_struct *source) {
	return source->count == source->capacity; // Returns true if the count of items equals the capacity
}

// Returns the number of items in the priority queue
int pq_count(const pq_struct *source) {
	return source->count;  // Returns the count of items
}

// Inserts an item into the priority queue
bool pq_insert(pq_struct *source, data_type *item) {
	if (pq_full(source)) {
		return false;  // Return false if the queue is full
	}
	// Insert the item at the end of the queue
	source->items[(source->first + source->count) % source->capacity] = *item;
	source->count++;  // Increment the count of items
	return true;  // Return true to indicate the item was inserted
}

// Peeks at the highest priority item in the priority queue
bool pq_peek(const pq_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;  // Return false if the queue is empty
	}
	*item = source->items[source->first]; // Copy the highest priority item to the provided pointer
	return true;  // Return true to indicate the item was peeked
}

// Removes the highest priority item from the priority queue
bool pq_remove(pq_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;  // Return false if the queue is empty
	}
	*item = source->items[source->first]; // Copy the highest priority item to the provided pointer
	// Move the index of the highest priority item to the next one
	source->first = (source->first + 1) % source->capacity;
	source->count--;  // Decrement the count of items
	return true;  // Return true to indicate the item was removed
}

// Prints all items in the priority queue (for testing)
void pq_print(const pq_struct *source) {
	for (int i = 0; i < source->count; i++) {
		int index = (source->first + i) % source->capacity; // Calculate the index of each item
		// Assuming `data_type` can be printed using `printf`
		printf("Item %d: %d\n", i, source->items[index]);  // Print the item
	}
}
