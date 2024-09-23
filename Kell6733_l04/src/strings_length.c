/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long,
		int length) {

	// your code here
	// Loop through each string in the strings
	for (int i = 0; i < data->lines; i++) {
		// Check if the current string is shorter than the length
		if (strlen(data->strings[i]) < length) {
			fprintf(fp_short, "%s\n", data->strings[i]);
		}
		// Check if the current string is longer than the length
		else {
			fprintf(fp_long, "%s\n", data->strings[i]);

		}

	}
}
