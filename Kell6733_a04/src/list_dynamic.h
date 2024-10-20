/**
 * -------------------------------------
 * @file  list_dynamic.h
 * Dynamic List Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef LIST_DYNAMIC_H_
#define LIST_DYNAMIC_H_

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
 * Initial list size.
 */
#define LIST_INIT 12

/**
 * list header.
 */
typedef struct {
    int capacity;               // capacity of the list.
    int count;                  // count of items in list.
    data_type *items;		           	// array of data items.
} list_dynamic_struct;

// Prototypes

/**
 * Initializes a list.
 *
 * @param source - pointer to a list
 * @param capacity - the initial number of spaces for items in the stack.
 */
void list_initialize(list_dynamic_struct **source, int capacity);

/**
 * Destroys a list.
 *
 * @param source - pointer to a list
 */
void list_destroy(list_dynamic_struct **source);

/**
 * Determines if a list is empty.
 *
 * @param source - pointer to a list
 * @return - true if the list is empty, false otherwise
 */
bool list_empty(const list_dynamic_struct *source);

/**
 * Determines if the list is full
 * @param source - pointer to a list
 * @return - true if the list is full, false otherwise
 */
bool list_full(const list_dynamic_struct *source);

/**
 * Appends a item to the end of a list.
 *
 * @param source - pointer to a list
 * @param item - the item to append
 * @return - true if item appended, false otherwise (list is full)
 */
bool list_append(list_dynamic_struct *source, data_type *item);

/**
 * Returns the number of items in the list.
 *
 * @param source - pointer to a list
 * @return - the number of items in the list
 */
int list_count(const list_dynamic_struct *source);

/**
 * Inserts a item to a list at location i. All items to the right
 * of list[i] must be moved to the next index.
 *
 * @param source - pointer to a list
 * @param item - the item to insert
 * @param i - the index to put the new item
 * @return - true if item inserted, false otherwise (list is full)
 */
bool list_insert(list_dynamic_struct *source, data_type *item, int i);

/**
 * Returns a copy of the item on the front of a list. list is unchanged.
 *
 * @param source - pointer to a list
 * @param item - the item to peek
 * @return - true if item peeked, false otherwise (list is empty)
 */
bool list_peek(const list_dynamic_struct *source, data_type *item);

/**
 * Removes and returns the item at index i from a list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param item - a copy of the item removed
 * @param i - index of item to remove
 * @return - true if item is removed, false otherwise
 */
bool list_index_remove(list_dynamic_struct *source, data_type *item, int i);

/**
 * Returns a copy of the item matching key in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_find(const list_dynamic_struct *source, const data_type *key, data_type *item);

/**
 * Removes and returns the item matching key from the list. All items to the right
 * of list[i] must be moved to the previous index.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - true if key is found, false otherwise
 */
bool list_key_remove(list_dynamic_struct *source, const data_type *key, data_type *item);

/**
 * Returns the index of key in list. -1 if key not in list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - index of the location of key in list
 */
int list_key_index(const list_dynamic_struct *source, const data_type *key);

/**
 * Determines if key is in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - true if key in list, false otherwise
 */
bool list_key_contains(const list_dynamic_struct *source, const data_type *key);

/**
 * Determines number of times key appears in a list.
 *
 * @param source - pointer to a list
 * @param key - key of the item to find
 * @return - number of times key appears in list
 */
int list_key_count(const list_dynamic_struct *source, const data_type *key);

/**
 * Finds the maximum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the maximum item
 * @return - true if a maximum value is found, false otherwise (list is empty)
 */
bool list_max(const list_dynamic_struct *source, data_type *item);

/**
 * Finds the minimum item in a list.
 *
 * @param source - pointer to a list
 * @param item - pointer to the minimum item
 * @return - true if a minimum value is found, false otherwise (list is empty)
 */
bool list_min(const list_dynamic_struct *source, data_type *item);

/**
 * Removes all duplicate items from a list. Only the first copy of each item remains
 * in the list.
 *
 * @param source - pointer to a list
 */
void list_clean(list_dynamic_struct *source);

/**
 * Compares two lists for equality. Lists are equal if they contain the equivalent items
 * in the same order.
 *
 * @param source - the first list to compare
 * @param target - the second list to compare
 * @return - true if lists are identical, false otherwise
 */
bool list_equal(const list_dynamic_struct *target, const list_dynamic_struct *source);

/**
 * Prints the items in a list from front to rear.
 *
 * @param source - pointer to a list.
 */
void list_print(const list_dynamic_struct *source);

#endif /* LIST_DYNAMIC_H_ */
