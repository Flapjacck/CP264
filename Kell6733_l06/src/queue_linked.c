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
	// Allocate memory
	queue_node *new_node = (queue_node*) malloc(sizeof(queue_node));

	// Copy the item into the new node
	new_node->item = item;
	new_node->next = NULL;

	// If the queue is empty, new node becomes both the front and rear
	if (source->rear == NULL) {
		source->front = new_node;
		source->rear = new_node;
	} else {
		// Attach the new node to the end of the queue and update the rear
		source->rear->next = new_node;
		source->rear = new_node;
	}

	// Increase the count
	source->count++;
}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {

	// your code here
	// Check if the queue is empty
	if (queue_empty(source)) {
		return FALSE;
	}
	// Copy the data
	data_copy(item, source->front->item);
	return TRUE;

}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {

	// your code here
	// Check if the queue is empty
	if (source->front == NULL) {
		return FALSE; // Queue is empty
	}

	// Get the front node and its item
	queue_node *temp = source->front;
	*item = temp->item;

	// Move the front pointer to the next node
	source->front = source->front->next;

	// If the front becomes NULL, then the queue is empty, update rear to NULL
	if (source->front == NULL) {
		source->rear = NULL;
	}

	// Free the memory of the removed node
	free(temp);

	// Decrease the count of items in the queue
	source->count--;

	// Return TRUE, the item has been removed
	return TRUE;

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
