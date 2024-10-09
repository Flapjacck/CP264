/**
 * -------------------------------------
 * @file  stack_linked.c
 * Linked Stack Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "stack_linked.h"

// Functions

stack_linked* stack_initialize() {
    // Allocate memory to the stack header
    stack_linked *source = malloc(sizeof *source);
    // Initialize the stack top
    source->top = NULL;
    return source;
}

void stack_free(stack_linked **source) {
    // Free the linked data
    while((*source)->top != NULL) {
        stack_node *temp = (*source)->top;
        // use the data_free function to free the actual data
        data_free(&temp->item);
        // update the stack top
        (*source)->top = (*source)->top->next;
        // free the stack node
        free(temp);
        temp = NULL;
    }
    // Free the stack header
    free(*source);
    *source = NULL;
    return;
}

BOOLEAN stack_empty(const stack_linked *source) {
    return (source->top == NULL);
}

void stack_push(stack_linked *source, data_ptr item) {
    // allocate memory to a new stack node
    stack_node *node = malloc(sizeof *node);
    // allocate memoory for the data
    node->item = malloc(sizeof *node->item);
    // copy the data parameter to the new memory
    data_copy(node->item, item);
    // update the stack top
    node->next = source->top;
    source->top = node;
}

BOOLEAN stack_peek(const stack_linked *source, data_ptr item) {
    BOOLEAN peeked = FALSE;

    if(source->top != NULL) {
        // return a copy of the data in the node
        data_copy(item, source->top->item);
        peeked = TRUE;
    }
    return peeked;
}

BOOLEAN stack_pop(stack_linked *source, data_ptr *item) {
    BOOLEAN popped = FALSE;

    if(source->top != NULL) {
        // return a pointer to the node data
        *item = source->top->item;
        stack_node *temp = source->top;
        // update the stack top and free the removed node
        source->top = source->top->next;
        free(temp);
        popped = TRUE;
    }
    return popped;
}

void stack_print(const stack_linked *source) {
    char string[DATA_STRING_SIZE];
    stack_node *current = source->top;

    while(current != NULL) {
        printf("%s\n", data_string(string, sizeof string, current->item));
        current = current->next;
    }
}
