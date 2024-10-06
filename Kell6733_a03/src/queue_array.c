/**
 * -------------------------------------
 * @file  queue_array.c
 * queue_array Source Code File
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "queue_array.h"

// Functions

// your code here (include all stubs!)

//initialize the queue
void queue_initialize(queue_struct *source) {
	source->front = 0;
	source->rear = -1;
	source->count = 0;
}

//check if the queue is empty
bool queue_empty(const queue_struct *source) {
	return source->count == 0;
}

//check if the queue is full
bool queue_full(const queue_struct *source) {
	return source->count == source->capacity;
}

//function to return the count of the queue
int queue_count(const queue_struct *source) {
	return source->count;
}

//inserts an item into the queue
bool queue_insert(queue_struct *source, data_type *item) {
	if (queue_full(source)) {
		printf("Queue is full\n");
		return false;
	}
	//adds an element in the queue
	source->rear = (source->rear + 1) % source->capacity;
	source->items[source->rear] = *item;
	source->count++;
	return true;
}

//checks the first element in the queue
bool queue_peek(const queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return false;
	}
	*item = source->items[source->front];
	return true;
}

//removes the first element in the queue
bool queue_remove(queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return false;
	}
	//removes the first element in the queue
	*item = source->items[source->front];
	source->front = (source->front + 1) % source->capacity;
	source->count--;
	return true;
}

//prints the queue
void queue_print(const queue_struct *source) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return;
	}
	int i = source->front;
	while (i != source->rear) {
		data_print(&source->items[i]);
		printf("\n");
		i = (i + 1) % source->capacity;
	}
}
