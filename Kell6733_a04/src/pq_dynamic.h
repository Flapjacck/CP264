/**
 * -------------------------------------
 * @file  PQ_DYNAMIC.h
 * Dynamic Priority Queue Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef PQ_DYNAMIC_H_
#define PQ_DYNAMIC_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "data.h"

/**
 * Initial priority queue size.
 */
#define PQ_INIT 12

/**
 * priority queue header.
 */
typedef struct {
    int capacity;               // capacity of a priority queue.
    int count;                  // count of items in pq.
    int first;                  // index of highest priority item of a priority queue.
                                // -1 if priority queue is empty
    data_type *items;           // array of data items.
} pq_dynamic_struct;

// Prototypes

/**
 * Initializes a priority queue.
 *
 * @param source - pointer to a priority queue to initialize.
 * @param capacity - the initial number of spaces for items in the priority queue.
 */
void pq_initialize(pq_dynamic_struct **source, int capacity);

/**
 * Destroys a priority queue.
 *
 * @param source - pointer to a priority queue
 */
void pq_destroy(pq_dynamic_struct **source);

/**
 * Determines if a priority queue is empty.
 *
 * @param source - pointer to a priority queue
 * @return true if a priority queue is empty, false otherwise
 */
bool pq_empty(const pq_dynamic_struct *source);

/**
 * Determines if a priority queue is full.
 *
 * @param source - pointer to a priority queue
 * @return true if a priority queue is full, false otherwise
 */
bool pq_full(const pq_dynamic_struct *source);

/**
 * Returns the number of items in a priority queue.
 *
 * @param source - pointer to a priority queue
 * @return - the number of items in a priority queue
 */
int pq_count(const pq_dynamic_struct *source);

/**
 * Inserts an item into a priority queue.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise (pq is full)
 */
bool pq_insert(pq_dynamic_struct *source, data_type *item);

/**
 * Returns a copy of the highest priority item in a priority queue.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (pq is empty)
 */
bool pq_peek(const pq_dynamic_struct *source, data_type *item);

/**
 * Returns and removes the item on the front of a priority queue.
 * first is reset to -1 if priority queue becomes empty.
 *
 * @param source - pointer to a priority queue
 * @param item - the item to peek
 * @return - true if item removed, false otherwise (pq is empty)
 */
bool pq_remove(pq_dynamic_struct *source, data_type *item);

/**
 * Prints the items in a priority queue from front to rear.
 * (For testing only).
 *
 * @param source - pointer to a priority queue
 */
void pq_print(const pq_dynamic_struct *source);

#endif /* PQ_DYNAMIC_H_ */
