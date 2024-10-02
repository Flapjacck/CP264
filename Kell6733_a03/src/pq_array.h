/**
 * -------------------------------------
 * @file  pq_array.h
 * Array-Based Priority Queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef PQ_ARRAY_H_
#define PQ_ARRAY_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"

/**
 * Initial priority queue size.
 */
#define PQ_INIT 12

/**
 * priority queue structure.
 */
typedef struct {
    int capacity;                // capacity of a priority queue.
    int count;                   // count of items in pq.
    int first;                   // index of highest priority item of a priority queue.
    data_type items[PQ_INIT];    // array of data items.
} pq_struct;

/**
 * Initializes a priority queue.
 *
 * @param source - the priority queue to initialize.
 */
void pq_initialize(pq_struct *source);

/**
 * Determines if a priority queue is empty.
 *
 * @param source - pointer to a priority queue.
 * @return - true if a priority queue is empty, false otherwise.
 */
bool pq_empty(const pq_struct *source);

/**
 * Determines if a priority queue is full.
 *
 * @param source - pointer to a priority queue.
 * @return - true if a priority queue is full, false otherwise.
 */
bool pq_full(const pq_struct *source);

/**
 * Returns the number of items in a priority queue.
 *
 * @param source - pointer to a priority queue.
 * @return - the number of items in a priority queue.
 */
int pq_count(const pq_struct *source);

/**
 * Inserts an item into a priority queue.
 *
 * @param source - pointer to a priority queue.
 * @param item - the item to insert.
 * @return - true if item inserted, false otherwise (pq is full)
 */
bool pq_insert(pq_struct *source, data_type *item);

/**
 * Returns a copy of the highest priority item in a priority queue.
 *
 * @param source - pointer to a priority queue.
 * @param item - the item to peek.
 * @return - true if item peeked, false otherwise (pq is empty)
 */
bool pq_peek(const pq_struct *source, data_type *item);

/**
 * Returns and removes the item on the front of a priority queue.
 *
 * @param source - pointer to a priority queue.
 * @param item - the item to peek.
 * @return - true if item removed, false otherwise (pq is empty)
 */
bool pq_remove(pq_struct *source, data_type *item);

/**
 * Prints the items in a priority queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a priority queue
 */
void pq_print(const pq_struct *source);

#endif /* PQ_ARRAY_H_ */
