/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {

	// your code here
	// Allocate memory
	queue_linked *queue = (queue_linked*) malloc(sizeof(queue_linked));
	// Initialize values
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
	return queue;

}

void queue_free(queue_linked **source) {

	// your code here
	// Free memory
	queue_node *current = (*source)->front;
	queue_node *temp;
	// Free each node
	while (current != NULL) {
		temp = current;
		current = current->next;
		free(temp->item);
		free(temp);
	}
	// Free queue
	free(*source);
	*source = NULL;

}

BOOLEAN queue_empty(const queue_linked *source) {

	// your code here
	// Check if the queue is empty
	return source->count == 0;

}

int queue_count(const queue_linked *source) {

	// your code here
	// Return the count
	return source->count;

}

void queue_insert(queue_linked *source, data_ptr item) {

	// your code here

}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {

	// your code here

}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {

	// your code here

}

void queue_print(const queue_linked *source) {
	char string[DATA_STRING_SIZE];
	queue_node *current = source->front;

	while (current != NULL) {
		printf("%s\n", data_string(string, sizeof string, current->item));
		current = current->next;
	}
	return;
}
