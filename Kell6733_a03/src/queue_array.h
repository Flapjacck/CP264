/**
 * -------------------------------------
 * @file  queue_array.h
 * Lab 4 Array-Based queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef QUEUE_ARRAY_H_X_
#define QUEUE_ARRAY_H_X_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"

/**
 * Initial queue size.
 */
#define QUEUE_INIT 12

/**
 * queue structure.
 */
typedef struct {
    int capacity;                // capacity of the queue.
    int count;                   // count of items in queue.
    int front;                   // index of front item of the queue.
    int rear;                    // index of rear item of the queue.
    data_type items[QUEUE_INIT]; // array of data items.
} queue_struct;

/**
 * Initializes a queue.
 *
 * @param queue - the queue to initialize.
 */
void queue_initialize(queue_struct *source);

/**
 * Determines if a queue is empty.
 *
 * @param source - pointer to a queue.
 * @return - true if source is empty, false otherwise.
 */
bool queue_empty(const queue_struct *source);

/**
 * Determines if a queue is full.
 *
 * @param source - pointer to a queue.
 * @return - true if source is full, false otherwise.
 */
bool queue_full(const queue_struct *source);

/**
 * Returns the number of items in a queue.
 *
 * @param source - pointer to a queue.
 * @return - the number of items in source.
 */
int queue_count(const queue_struct *source);

/**
 * Inserts an item into a queue.
 *
 * @param source - pointer to a queue.
 * @param item - the item to insert.
 * @return - true if item inserted, false otherwise (queue is full)
 */
bool queue_insert(queue_struct *source, data_type *item);

/**
 * Returns a copy of the item on the front of a queue. queue is unchanged.
 *
 * @param source - pointer to a queue.
 * @param item - the item to peek.
 * @return - true if item peeked, false otherwise (queue is empty)
 */
bool queue_peek(const queue_struct *source, data_type *item);

/**
 * Returns and removes the item on the front of a queue.
 *
 * @param source - pointer to a queue.
 * @param item - the item to peek.
 * @return - true if item removeped, false otherwise (queue is empty)
 */
bool queue_remove(queue_struct *source, data_type *item);

/**
 * Prints the items in a queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a queue
 */
void queue_print(const queue_struct *sourcee);

#endif /* QUEUE_ARRAY_H_X_ */
