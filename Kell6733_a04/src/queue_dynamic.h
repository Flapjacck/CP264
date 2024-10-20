/**
 * -------------------------------------
 * @file  queue_dynamic.h
 * Dynamic Queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_DYNAMIC_H_
#define QUEUE_DYNAMIC_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "data.h"

// typedefs

// Structures
/**
 * Initial queue size.
 */
#define QUEUE_INIT 12

/**
 * queue header.
 */
typedef struct {
    int capacity;      // capacity of the queue.
    int count;         // count of items in queue.
    int front;         // index of front item of the queue.
    int rear;          // index of rear item of the queue.
    data_type *items;		  	// pointer to array of data items.
} queue_dynamic_struct;

// Prototypes

/**
 * Initializes a queue.
 *
 * @param source - pointer to a queue to initialize
 * @param @param capacity - the initial number of spaces for items in the queue.
 */
void queue_initialize(queue_dynamic_struct **source, int capacity);

/**
 * Destroys a queue.
 *
 * @param source - pointer to a queue
 */
void queue_destroy(queue_dynamic_struct **source);

/**
 * Determines if a queue is empty.
 *
 * @param source - pointer to a queue
 * @return true if the queue is empty, false otherwise
 */
bool queue_empty(const queue_dynamic_struct *source);

/**
 * Determines if the queue is full.
 *
 * @param source - pointer to a queue
 * @return - true if the queue is full, false otherwise
 */
bool queue_full(const queue_dynamic_struct *source);

/**
 * Returns the number of items in the queue.
 *
 * @param source - pointer to a queue
 * @return - the number of items in the queue
 */
int queue_count(const queue_dynamic_struct *source);

/**
 * Inserts an item into a queue.
 *
 * @param source - pointer to a queue
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise (queue is full)
 */
bool queue_insert(queue_dynamic_struct *source, data_type *item);

/**
 * Returns a copy of the item on the front of a queue. queue is unchanged.
 *
 * @param source - pointer to a queue
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (queue is empty)
 */
bool queue_peek(const queue_dynamic_struct *source, data_type *item);

/**
 * Returns and removes the item on the front of a queue.
 *
 * @param source - pointer to a queue
 * @param item - the item to peek
 * @return - true if item removed, false otherwise (queue is empty)
 */
bool queue_remove(queue_dynamic_struct *source, data_type *item);

/**
 * Prints the items in a queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a queue
 */
void queue_print(const queue_dynamic_struct *source);

#endif /* QUEUE_DYNAMIC_H_ */
