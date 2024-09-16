/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"
#include <string.h>

int sum_three_integers(void) {

	// your code here
	// Declare variables
	int num1, num2, num3, sum;
	// Declare a string to store user input
	char line[STRING_SMALL];

	printf("Enter three integers separated by commas: ");
	// Read integers from stdin/user input
	while (fgets(line, sizeof(line), stdin)) {
		// If three integers are read, break the loop
		if (sscanf(line, "%d, %d, %d", &num1, &num2, &num3) == 3) {
			sum = num1 + num2 + num3;
			break;

		}
		// If the user input is not three integers, prompt the user to enter three integers
		else {
			printf("The integers were not properly entered.\n");
			printf("Enter three integers separated by commas: ");
		}
	}

	return sum;

}
