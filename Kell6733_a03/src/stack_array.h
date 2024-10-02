/**
 * -------------------------------------
 * @file  stack_array.h
 * stack_array Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"

/**
 * Initial stack size.
 */
#define STACK_INIT 12

/**
 * stack structure.
 */
typedef struct {
    int capacity;                // current capacity of the stack.
    int top;                     // index of top item of the stack.
    data_type items[STACK_INIT]; // array of data items.
} stack_struct;

/**
 * Initializes a stack.
 *
 * @param source - the stack to initialize.
 */
void stack_initialize(stack_struct *source);

/**
 * Determines if a stack is empty.
 *
 * @param stack - pointer to a stack.
 * @return - true if source is empty, false otherwise.
 */
bool stack_empty(const stack_struct *source);

/**
 * Determines if a stack is full.
 *
 * @param source - pointer to a stack.
 * @return - true if source is full, false otherwise.
 */
bool stack_full(const stack_struct *source);

/**
 * Pushes an item onto a stack.
 *
 * @param source - pointer to a stack.
 * @param item - the item to push.
 * @return - true if item pushed, false otherwise (stack is full)
 */
bool stack_push(stack_struct *source, data_type *item);

/**
 * Returns a copy of the item on the top of a stack. stack is unchanged.
 *
 * @param source - pointer to a stack.
 * @param item - the item to peek.
 * @return - true if item peeked, false otherwise (stack is empty)
 */
bool stack_peek(const stack_struct *source, data_type *item);

/**
 * Returns and removes the item on the top of a stack.
 *
 * @param source - pointer to a stack.
 * @param item - the item to peek.
 * @return - true if item popped, false otherwise (stack is empty)
 */
bool stack_pop(stack_struct *source, data_type *item);

/**
 * Prints the items in a stack from top to bottom.
 * (For testing only).
 *
 * @param source - pointer to a stack
 */
void stack_print(const stack_struct *source);

#endif /* STACK_ARRAY_H_ */
