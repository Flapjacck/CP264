/**
 * -------------------------------------
 * @file  main.c
 * Lab 5 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-13
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "data2.h"
#include "stack_linked.h"
#include "queue_linked.h"

#define SIZE 128

/**
 * Simple stack testing.
 */
void test_stack(void) {
    char buffer[SIZE];

    data_ptr item;

    printf("\n-------------------------------------\n");
    printf("Initialize stack\n");
    stack_linked *stack = stack_initialize();
    printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(stack)));
    printf("Add data to stack:\n");

    item = malloc((DATA_STRING_SIZE + 1) * sizeof(char));
    strcpy(item, "Lori");
    stack_push(stack, item);
    strcpy(item, "Tristan");
    stack_push(stack, item);
    strcpy(item, "Tasmin");
    stack_push(stack, item);
    strcpy(item, "David");
    stack_push(stack, item);

    printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(stack)));
    stack_peek(stack, item);
    printf("Stack peek: ");
    printf("%s\n", data_string(buffer, SIZE, item));
    printf("\n");
    printf("Contents of stack:\n");
    stack_print(stack);

    printf("Empty out the stack:\n");

    while(!stack_empty(stack)) {
        stack_pop(stack, &item);
        printf("  Popped: %s\n", data_string(buffer, SIZE, item));
        data_free(&item);
    }
    printf("Stack empty: %s\n", BOOL_TO_STR(stack_empty(stack)));
    printf("Destroy the stack:\n");
    stack_free(&stack);

    if(stack == NULL) {
        printf("Destroyed!\n");
    } else {
        printf("D'oh!\n");
    }
}

/**
 * Simple queue testing.
 */
void test_queue(void) {
    char buffer[SIZE];

    data_ptr item;

    printf("\n-------------------------------------\n");
    printf("Initialize queue\n");
    queue_linked *queue = queue_initialize();
    printf("Queue empty: %s\n", BOOL_TO_STR(queue_empty(queue)));
    printf("Add data to queue:\n");

    item = malloc((DATA_STRING_SIZE + 1) * sizeof(char));
    strcpy(item, "Lori");
    queue_insert(queue, item);
    strcpy(item, "Tristan");
    queue_insert(queue, item);
    strcpy(item, "Tasmin");
    queue_insert(queue, item);
    strcpy(item, "David");
    queue_insert(queue, item);

    printf("Queue empty: %s\n", BOOL_TO_STR(queue_empty(queue)));
    queue_peek(queue, item);
    printf("Queue peek: ");
    printf("%s\n", data_string(buffer, SIZE, item));
    printf("\n");
    printf("Contents of queue:\n");
    queue_print(queue);

    printf("Empty out the queue:\n");

    while(!queue_empty(queue)) {
        BOOLEAN removed = queue_remove(queue, &item);
        printf("  Removed: %s, %s\n", BOOL_TO_STR(removed), data_string(buffer, SIZE, item));
    }
    printf("Queue empty: %s\n", BOOL_TO_STR(queue_empty(queue)));
    printf("Destroy the queue:\n");
    queue_free(&queue);

    if(queue == NULL) {
        printf("Destroyed!\n");
    } else {
        printf("D'oh!\n");
    }
}

/**
 * Test the file and string functions.
 *
 * @param argc - unused
 * @param args - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_stack();
    test_queue();

    return (EXIT_SUCCESS);
}
