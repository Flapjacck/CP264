/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"
#include <string.h>

void int_array_read(int *array, int size) {

	// your code here
	char line[STRING_SMALL];
	int num;
	int i = 0;

	printf("Enter %d values for an array of int.\n", size);
	printf("Value for index 0: ");

	// Read integers from stdin/user input
	while (fgets(line, sizeof(line), stdin)) {
		// If an integer is read, add it to the array
		if (sscanf(line, "%d", &num) == 1) {
			array[i] = num;
			i++;
			printf("Value for index %d: ", i);
			// If the array is full, break the loop
			if (i == size) {
				break;
			}
		}
		// If a error is entered, prompt the user to enter a valid integer
		else {
			printf("Not a valid integer\n");
			printf("Value for index %d: ", i);
		}

	}

}
