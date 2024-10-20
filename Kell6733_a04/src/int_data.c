/**
 * -------------------------------------
 * @file  int_data.c
 * int_data Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
// Includes
#include "int_data.h"

// Functions

void int_copy(const int *source, int *target) {
    *target = *source;
}

void int_print(const int *source) {
    printf("%d", *source);
}

int int_compare(const int *source, const int *target) {
    int result = 0;

    if(*source < *target) {
        result = -1;
    } else if(*source > *target) {
        result = 1;
    }
    return (result);
}

int int_string(char *string, size_t size, const int *source) {
    return snprintf(string, size, "%d", *source);
}
