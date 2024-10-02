/**
 * -------------------------------------
 * @file  main.c
 * file description
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "movie_utilities.h"
#include "stack_array.h"
#include "queue_array.h"
#include "pq_array.h"

#define SEP "-------------------------------------\n"

void test_stack_generic(data_type values[], int count) {
    data_type item;

    stack_struct source;
    stack_initialize(&source);

    printf("Testing stack_array\n");
    printf(SEP);
    printf("stack_empty: %s\n", BOOL_TO_STR(stack_empty(&source)));
    printf(SEP);
    printf("stack_push\n");

    for(int i = 0; i < count; i++) {
        printf("push: ");
        data_print(&values[i]);
        printf("\n");
        stack_push(&source, &values[i]);
    }
    printf(SEP);
    printf("stack_empty: %s\n", BOOL_TO_STR(stack_empty(&source)));
    printf(SEP);
    printf("stack_peek\n");
    stack_peek(&source, &item);
    printf("item: ");
    data_print(&item);
    printf("\n");
    printf(SEP);
    printf("stack_print\n");
    stack_print(&source);
    printf(SEP);
    printf("stack_pop\n");

    while(!stack_empty(&source)) {
        stack_pop(&source, &item);
        printf("popped: ");
        data_print(&item);
        printf("\n");
    }
}

void test_stack_int() {
    // Test the stack with integer data.
    data_type values[] = {2, 4, 1, 7, 4, 2, 9};
    const int COUNT = sizeof values / sizeof *values;
    test_stack_generic(values, COUNT);
}

/*
 void test_stack_movie() {
 // Test the stack with movie data
 movie_array_struct movies;
 FILE *fp = fopen("movies.txt", "r");
 read_movies(&movies, fp);
 fclose(fp);
 test_stack_generic(movies.items, movies.count);
 }
 */

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_stack_int();
    // test_stack_movie();
    printf(SEP);
    return (0);
}
