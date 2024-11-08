/**
 * -------------------------------------
 * @file  list_linked.h
 * linked List Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-11-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef LIST_linked_H_
#define LIST_linked_H_

// Includes
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

//==================================================================================
// typedefs

/**
 * List node.
 */
typedef struct list_node {
    data_ptr item;           // Pointer to the node data.
    struct list_node *next; // Pointer to the next list node.
} list_node;

/**
 * list header.
 */
typedef struct {
    list_node *front; // Pointer to the front node of the list.
    list_node *rear;  // Pointer to the rear node of the list.
    int count;        // count of items in list.
} list_linked;

//==================================================================================
// Prototypes

/**
 * Initializes a list.
 *
 * @return - pointer to a new list
 */
list_linked* list_initialize();

/**
 * Frees list memory.
 *
 * @param source - pointer to source
 */
void list_free(list_linked **source);

/**
 * Determines if source is empty.
 *
 * @param source - pointer to source
 * @return - TRUE if source is empty, FALSE otherwise
 */
BOOLEAN list_empty(const list_linked *source);

/**
 * Determines if source is full.
 * (Cheat - returns FALSE at all times.)
 *
 * @param source - pointer to source
 * @return - TRUE if source is full, FALSE otherwise
 */
BOOLEAN list_full(const list_linked *source);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to source
 * @return - the number of items in source
 */
int list_count(const list_linked *source);

/**
 * Appends a item to the rear of source.
 *
 * @param source - pointer to source
 * @param item - the item to append
 * @return - TRUE if item appended, FALSE otherwise (list is full)
 */
BOOLEAN list_append(list_linked *source, data_ptr item);

/**
 * Prepends a item to the front of source.
 *
 * @param source - pointer to source
 * @param item - the item to prepend
 * @return - TRUE if item prepended, FALSE otherwise (list is full)
 */
BOOLEAN list_prepend(list_linked *source, data_ptr item);

/**
 * Returns the number of items in source.
 *
 * @param source - pointer to source
 * @return the number of items in source
 */
int list_count(const list_linked *source);

/**
 * Inserts a item in source at location i.
 * If i is less than 0 the new item is prepended to source.
 * If i is greater than the length of source the new item is appended to source.
 *
 * @param source - pointer to source
 * @param item - the item to insert
 * @param i - the index to put the new item
 * @return - TRUE if item inserted, FALSE otherwise (list is full)
 */
BOOLEAN list_insert(list_linked *source, data_ptr item, int i);

/**
 * Returns a copy of the item at the front of source. source is unchanged.
 *
 * @param source - pointer to source
 * @param item - the item to peek
 * @return - TRUE if item peeked, FALSE otherwise (list is empty)
 */
BOOLEAN list_peek(const list_linked *source, data_ptr item);

/**
 * Removes and returns the item at index i from source.
 *
 * @param source - pointer to source
 * @param item - a copy of the item removed
 * @param i - index of item to remove
 * @return - TRUE if item is removed, FALSE otherwise
 */
BOOLEAN list_index_remove(list_linked *source, data_ptr item, int i);

/**
 * Returns a copy of the item matching key in source.
 *
 * @param source - pointer to source
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - TRUE if key is found, FALSE otherwise
 */
BOOLEAN list_key_find(const list_linked *source, const data_ptr key, data_ptr item);

/**
 * Removes and returns the item matching key from source.
 *
 * @param source - pointer to source
 * @param key - key of the item to find
 * @param item - a copy of the item found
 * @return - TRUE if key is found, FALSE otherwise
 */
BOOLEAN list_key_remove(list_linked *source, const data_ptr key, data_ptr item);

/**
 * Removes and returns the first item in source. Returns FALSE if source is empty.
 *
 * @param source - pointer to source.
 * @param item - a copy of the item removed.
 * @return - TRUE if item removed, FALSE otherwise.
 */
BOOLEAN list_remove_front(list_linked *source, data_ptr item);

/**
 * Returns the index of key in source. -1 if key not in source.
 *
 * @param source - pointer to source
 * @param key - key of the item to find
 * @return - index of the location of key in source
 */
int list_key_index(const list_linked *source, const data_ptr key);

/**
 * Determines if key is in source.
 *
 * @param source - pointer to source
 * @param key - key of the item to find
 * @return - TRUE if key in source, FALSE otherwise
 */
BOOLEAN list_key_contains(const list_linked *source, const data_ptr key);

/**
 * Determines number of times key appears in source.
 *
 * @param source - pointer to source
 * @param key - key of the item to find
 * @return - number of times key appears in source
 */
int list_key_count(const list_linked *source, const data_ptr key);

/**
 * Finds the maximum item in source.
 *
 * @param source - pointer to source
 * @param item - pointer to the maximum item
 * @return - TRUE if a maximum value is found, FALSE otherwise (list is empty)
 */
BOOLEAN list_max(const list_linked *source, data_ptr item);

/**
 * Finds the minimum item in source.
 *
 * @param source - pointer to source
 * @param item - pointer to the minimum item
 * @return - TRUE if a minimum value is found, FALSE otherwise (list is empty)
 */
BOOLEAN list_min(const list_linked *source, data_ptr item);

/**
 * Removes all duplicate items from source. Only the first copy of each item remains
 * in source.
 *
 * @param source - pointer to source
 */
void list_clean(list_linked *source);

/**
 * Compares two lists for equality. Lists are equal if they contain the equivalent items
 * in the same order.
 *
 * @param source - the first list to compare
 * @param target - the second list to compare
 * @return - TRUE if lists are identical, FALSE otherwise
 */
BOOLEAN list_equal(const list_linked *target, const list_linked *source);

/**
 * Combines the contents of two source lists into a target list. Items alternate.
 * Source lists are empty (not destroyed) when the function completes.
 * Moves nodes, not data.
 *
 * @param target - pointer to target list
 * @param source1 - pointer to first source list
 * @param source2 - pointer to second source list
 */
void list_combine(list_linked *target, list_linked *source1, list_linked *source2);

/**
 * Splits a source list alternately into two target lists. Items alternate.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to source list
 */
void list_split_alt(list_linked *target1, list_linked *target2, list_linked *source);

/**
 * Splits a source list into two target lists at the middle of the source list.
 * If the source list is even in size, it is split evenly.
 * If the source list is odd in size, target1 gets the large half of source.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to first target list
 * @param target2 - pointer to second target list
 * @param source - pointer to source list
 */
void list_split(list_linked *target1, list_linked *target2, list_linked *source);

/**
 * Splits a source list into two target lists based upon a key value.
 * target1 contains all values < key, target2 contains all values >= key.
 * Source list is empty (not destroyed) when function completes.
 * Moves nodes, not data.
 *
 * @param target1 - pointer to target1
 * @param target2 - pointer to target2
 * @param source - pointer to source
 * @param key - item to split list with
 */
void list_split_key(list_linked *target1, list_linked *target2, list_linked *source, data_ptr key);

/**
 * Returns a copy of source. Initializes the target list.
 *
 * @param source - pointer to the source list
 * @return - pointer to target
 */
list_linked* list_copy(const list_linked *source);

/**
 * Prints the items in source from front to rear.
 *
 * @param source - pointer to source.
 */
void list_print(const list_linked *source);

#endif /* LIST_linked_H_ */
