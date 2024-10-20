/**
 * -------------------------------------
 * @file  stack_dynamic.c
 * Dynamic Stack Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "stack_dynamic.h"

// Functions

// Initializes a stack.
void stack_initialize(stack_dynamic_struct **source, int capacity) {
    // allocate memory to the entire structure
    *source = malloc(sizeof **source);
    // verify that memory was allocated
    assert((*source) != NULL);
    // initialize the capacity
    (*source)->capacity = capacity;
    // allocate memory to the array of items
    (*source)->items = malloc(capacity * sizeof(*source)->items);
    // verify that memory was allocated
    assert((*source)->items != NULL);
    (*source)->top = -1;
    return;
}

// Destroys a stack.
void stack_destroy(stack_dynamic_struct **source) {
    // Free the array data
    free((*source)->items);
    (*source)->items = NULL;
    // Free the stack header
    free(*source);
    *source = NULL;
    return;
}

// Determines if a stack is empty.
bool stack_empty(const stack_dynamic_struct *source) {
    return (source->top == -1);
}

// Determines if a stack is full.
bool stack_full(const stack_dynamic_struct *source) {
    return false;
}

// Pushes an item onto a stack.
bool stack_push(stack_dynamic_struct *source, const data_type *item) {
    bool pushed = true;
    source->top += 1;

    // If more memory is required, allocate it.
    if(source->top == source->capacity) {
        // Double the stack capacity.
        source->capacity *= 2;
        // printf("Reallocating\n"); // debugging
        data_type *ptr = realloc(source->items, source->capacity * sizeof source->items);
        // verify that memory was reallocated
        assert(ptr != NULL);
        source->items = ptr;
    }
    // Add the new data to the items array.
    data_copy(item, &(source->items[source->top]));
    return pushed;
}

// Returns a copy of the top of a stack.
bool stack_peek(const stack_dynamic_struct *source, data_type *item) {
    bool peeked = false;

    if(source->top > -1) {
        data_copy(&(source->items[source->top]), item);
        peeked = true;
    }
    return peeked;
}

// Returns and removes the item on the top of a stack.
bool stack_pop(stack_dynamic_struct *source, data_type *item) {
    bool popped = false;

    if(source->top > -1) {
        data_copy(&(source->items[source->top]), item);
        source->top--;
        popped = true;
    }
    return popped;
}

// Prints the items in a stack from top to bottom.
void stack_print(const stack_dynamic_struct *source) {
    // Walk through stack from top to bottom using indexes.
    for(int i = source->top; i > -1; i--) {
        data_print(&(source->items[i]));
        printf("\n");
    }
    return;
}
