/**
 * -------------------------------------
 * @file  functions.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */

#include "functions.h"

// Your code here

double feet_to_acres(int square_feet) {
	// 1 acre = 43560 sq ft
	double square_footage = square_feet / FEET_PER_ACRE;
	return square_footage;
}
