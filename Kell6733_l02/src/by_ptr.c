/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {

	for (int i = 0; i < size; i++) {
		*(values + i) = i + 1;
	}
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

	// your code here

}

void print_by_ptr(int *values, long int *squares, int size) {

	// your code here

}
