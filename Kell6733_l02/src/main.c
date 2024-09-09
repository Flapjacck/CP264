/**
 * -------------------------------------
 * @file  main.c
 * Lab 2 Main Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "by_index.h"
#include "by_ptr.h"

#define MAX_SIZE 8

/**
 * Test the array traversal functions.
 *
 * @param argc - count of elements in args
 * @param argv - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    int values[MAX_SIZE];
    long int squares[MAX_SIZE];

    printf("Using index-based arrays\n\n");
    fill_values_by_index(values, MAX_SIZE);
    fill_squares_by_index(values, squares, MAX_SIZE);
    print_by_index(values, squares, MAX_SIZE);
    printf("----------------------------------\n");
    printf("Using pointer-based arrays\n\n");
    fill_values_by_ptr(values, MAX_SIZE);
    fill_squares_by_ptr(values, squares, MAX_SIZE);
    print_by_ptr(values, squares, MAX_SIZE);

    return EXIT_SUCCESS;
}
