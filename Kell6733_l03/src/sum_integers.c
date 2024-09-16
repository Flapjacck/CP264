/**
 * -------------------------------------
 * @file  sum_integers.c
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

int sum_integers(void) {

	// your code here
	char line[STRING_BIG];
	int num, sum = 0;

	printf("Enter integers, one per line: \n");
	// Read integers from stdin/user input
	while (fgets(line, sizeof(line), stdin)) {
		// If an integer is read, add it to the sum
		if (sscanf(line, "%d", &num) == 1) {
			sum += num;
		}
		// If a blank line is read, break the loop
		else {
			break;
		}

	}

	return sum;
}
