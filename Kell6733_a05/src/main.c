/**
 * -------------------------------------
 * @file  main.c
 * Assignment 5 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-11-01
 *
 * -------------------------------------
 * Add other tests as appropriate.
 */
#include <stdio.h>
#include <stdlib.h>

#include "list_linked.h"

#define SIZE 128

/**
 * Simple list testing.
 */
void test_list(void) {
    char buffer[SIZE];
    data_ptr item = malloc(sizeof item);
    data_ptr temp = malloc(sizeof temp);
    list_linked *source = NULL;
    list_linked *target1 = NULL;
    list_linked *target2 = NULL;
    int values[] = {5, 3, 7, 1, 5, 8, 3};
    int num_values = sizeof(values) / sizeof(*values);

    printf("------------\n");
    printf("List testing\n");
    printf("------------\n");

    printf("Initialize list\n");
    source = list_initialize();

    printf("list empty: %s\n", BOOL_TO_STR(list_empty(source)));
    printf("list count: %d\n", list_count(source));

    printf("\nAppend data to list:\n");

    for(int i = 0; i < num_values; i++) {
        *item = values[i];

        if(list_append(source, item)) {
            printf("  Appended: %s\n", data_string(buffer, sizeof buffer, item));
        }
    }

    printf("List after appending:\n");
    list_print(source);

    *item = 99;
    int index = 3;
    if(list_insert(source, item, index)) {
        printf("\nInserted %s at index %d.\n", data_string(buffer, sizeof buffer, item), index);
    }

    printf("List after inserting:\n");
    list_print(source);

    *temp = 99;
    if(list_key_remove(source, temp, item)) {
        printf("\nRemoved item: %s\n", data_string(buffer, sizeof buffer, item));
    }

    printf("List after removing by key:\n");
    list_print(source);

    *temp = 1;
    if(list_key_find(source, temp, item)) {
        printf("\nFound item: %s\n", data_string(buffer, sizeof buffer, item));
    }

    if(list_max(source, item)) {
        printf("\nMax item: %s\n", data_string(buffer, sizeof buffer, item));
    }
    if(list_min(source, item)) {
        printf("Min item: %s\n", data_string(buffer, sizeof buffer, item));
    }

    printf("\nRemoving duplicates from the list.\n");
    list_clean(source);
    printf("List after removing duplicates:\n");
    list_print(source);

    printf("\nCopying the list.\n");
    target1 = list_copy(source);
    printf("Contents of copied list:\n");
    list_print(target1);

    printf("\nLists equal: %s\n", BOOL_TO_STR(list_equal(target1, source)));

    printf("\nRemove front of target1.\n");
    list_remove_front(target1, item);
    printf("Removed item: %s\n", data_string(buffer, sizeof buffer, item));

    printf("\nLists equal: %s\n", BOOL_TO_STR(list_equal(target1, source)));

    list_free(&target1);
    target1 = list_initialize();
    target2 = list_initialize();

    printf("\nSplit list alternating.\n");
    printf("Contents of source list:\n");
    list_print(source);
    list_split_alt(target1, target2, source);
    printf("Contents of target1 list:\n");
    list_print(target1);
    printf("Contents of target2 list:\n");
    list_print(target2);

    printf("\nCombine target lists back to source.\n");
    list_combine(source, target1, target2);
    printf("Contents of recombined list:\n");
    list_print(source);

    // other tests here

    // free the list
    list_free(&source);
    printf("\nlist freed: %p\n", source);
    // Clean up second list.
    list_free(&target1);
    list_free(&target2);
    data_free(&item);
    data_free(&temp);
}

/**
 * Test the list functions.
 *
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_list();

    return (EXIT_SUCCESS);
}

