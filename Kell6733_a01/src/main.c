/**
 * -------------------------------------
 * @file  main.c
 * Assignment 1 Main Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2023-09-07
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>

#include "functions.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	// Your code here
	double square_feet = 50000.0;  // example value
	double acres = feet_to_acres(square_feet);

	printf("Square footage: %.2f sq ft is equivalent to %.2f acres\n",
			square_feet, acres);

	return 0;
}
