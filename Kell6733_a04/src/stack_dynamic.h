/**
 * -------------------------------------
 * @file  stack_dynamic.h
 * Dynamic Stack Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef STACK_DYNAMIC_H_
#define STACK_DYNAMIC_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "data.h"

/**
 * Initial stack size.
 */
#define STACK_INIT 12

// typedefs

/**
 * Stack header.
 */
typedef struct {
    int capacity;               // current capacity of the stack.
    int top;                    // index of top item of the stack.
    data_type *items;           		// pointer to array of data items.
} stack_dynamic_struct;

// Prototypes

/**
 * Initializes a stack.
 *
 * @param source - pointer to the stack to initialize.
 * @param capacity - the initial number of spaces for items in the stack.
 */
void stack_initialize(stack_dynamic_struct **source, int capacity);

/**
 * Destroys a stack.
 *
 * @param source - pointer to a stack
 */
void stack_destroy(stack_dynamic_struct **source);

/**
 * Determines if a stack is empty.
 *
 * @param source - pointer to a stack.
 * @return - true if source is empty, false otherwise.
 */
bool stack_empty(const stack_dynamic_struct *source);

/**
 * Determines if the stack is full.
 * @param stack - pointer to a stack.
 * @return - true if the stack is full, false otherwise.
 */
bool stack_full(const stack_dynamic_struct *source);

/**
 * Pushes a copy of an item onto a stack.
 *
 * @param source - pointer to a stack
 * @param item - pointer to the item to push
 * @return - true if item pushed, false otherwise (stack is full)
 */
bool stack_push(stack_dynamic_struct *source, const data_type *item);

/**
 * Returns a copy of the item on the top of a stack, stack is unchanged.
 *
 * @param source - pointer to a stack
 * @param item - pointer to a copy of the item to retrieve
 * @return - true if item peeked, false otherwise (stack is empty)
 */
bool stack_peek(const stack_dynamic_struct *source, data_type *item);

/**
 * Removes and returns the item on the top of a stack.
 *
 * @param stack - pointer to a stack
 * @param item - pointer the item to remove
 * @return - true if item popped, false otherwise (stack is empty)
 */
bool stack_pop(stack_dynamic_struct *source, data_type *item);

/**
 * Prints the items in a stack from top to bottom.
 * (For testing only).
 *
 * @param stack - pointer to a stack
 */
void stack_print(const stack_dynamic_struct *source);

#endif /* STACK_DYNAMIC_H_ */
