/**
 * -------------------------------------
 * @file  min_heap.c
 * Minimum Heap Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-03-11
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

#define STRING_SIZE 80

// local functions

/**
 * Swaps two data values.
 *
 * @param a pointer to data.
 * @param b pointer to data.
 */
static void heap_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

/**
 * Moves the last value in source until it is in its correct location
 * in source.
 *
 * @param source - pointer to a heap
 */
static void heapify_up(min_heap *source) {

	// your code here
	// start with the last element
	int index = source->count - 1;
	while (index > 0) {
		// calculate the parent index
		int parent = (index - 1) / 2;
		// if the current value is greater than or equal to the parent, stop
		if (source->values[index] >= source->values[parent]) {
			break;
		}
		// swap the current value with the parent
		heap_swap(&source->values[index], &source->values[parent]);
		// move up to the parent index
		index = parent;
	}
	return;
}

/**
 * Moves a value down source to its correct position.
 *
 * @param source - pointer to a heap
 */
static void heapify_down(min_heap *source) {

	// your code here
	// start with the root element
	int index = 0;
	// while there is at least one child
	while (2 * index + 1 < source->count) {
		// calculate the left child index
		int left = 2 * index + 1;
		// calculate the right child index
		int right = 2 * index + 2;
		// assume the left child is the smallest
		int smallest = left;
		// if the right child is smaller, update smallest
		if (right < source->count
				&& source->values[right] < source->values[left]) {
			smallest = right;
		}
		// if the current value is less than or equal to the smallest child, stop
		if (source->values[index] <= source->values[smallest]) {
			break;
		}
		// swap the current value with the smallest child
		heap_swap(&source->values[index], &source->values[smallest]);
		// move down to the smallest child index
		index = smallest;
	}
	return;
}

// Public minimum heap functions

min_heap* min_heap_initialize(int capacity) {
	min_heap *source = malloc(sizeof *source);
	source->values = malloc(capacity * sizeof *source->values);
	source->capacity = capacity;
	source->count = 0;
	return source;
}

void min_heap_free(min_heap **source) {
	if (source && *source) {
		if ((*source)->values) {
			free((*source)->values);
			// Set the values pointer to NULL after freeing
			(*source)->values = NULL;
		}
		free(*source);
		// Set the source pointer to NULL after freeing
		*source = NULL;
	}
}

void min_heap_heapify(min_heap *source, int *keys, int count) {

	for (int i = 0; i < count; i++) {
		min_heap_insert(source, keys[i]);
	}
	return;
}

int min_heap_empty(const min_heap *source) {
	return (source->count == 0);
}

int min_heap_full(const min_heap *source) {
	return (source->count == source->capacity);
}

int min_heap_count(const min_heap *source) {
	return (source->count);
}

void min_heap_insert(min_heap *source, const int value) {
	// Add new value to end of the heap.
	source->values[source->count] = value;
	source->count++;
	// Fix the heap.
	heapify_up(source);
	return;
}

int min_heap_peek(const min_heap *source) {
	return (source->values[0]);
}

int min_heap_remove(min_heap *source) {
	int value = source->values[0];
	source->count--;

	if (source->count > 0) {
		// Move last value to top of heap.
		source->values[0] = source->values[source->count];
		// Fix the heap.
		heapify_down(source);
	}
	return value;
}

int min_heap_valid(const min_heap *source) {

	// your code here
	// check each parent node
	for (int i = 0; i < source->count / 2; i++) {
		// calculate the left child index
		int left = 2 * i + 1;
		// calculate the right child index
		int right = 2 * i + 2;
		// if the parent is greater than the left child, the heap is invalid
		if (left < source->count && source->values[i] > source->values[left]) {
			return 0;
		}
		// if the parent is greater than the right child, the heap is invalid
		if (right < source->count
				&& source->values[i] > source->values[right]) {
			return 0;
		}
	}
	// the heap is valid
	return 1;
}

int min_heap_replace(min_heap *source, int replacement) {
	int value = source->values[0];
	source->values[0] = replacement;
	heapify_down(source);
	return value;
}

void heap_sort(int *values, int count) {

	// your code here
	// initialize a new heap
	min_heap *heap = min_heap_initialize(count);
	for (int i = 0; i < count; i++) {
		// insert all values into the heap
		min_heap_insert(heap, values[i]);
	}
	for (int i = 0; i < count; i++) {
		// remove values from the heap in sorted order
		values[i] = min_heap_remove(heap);
	}
	// free the heap
	min_heap_free(&heap);
	return;
}

// for testing
void min_heap_print(const min_heap *source) {
	printf("{");

	for (int i = 0; i < source->count; i++) {
		printf("%d, ", source->values[i]);
	}
	printf("}\n");
	return;
}
