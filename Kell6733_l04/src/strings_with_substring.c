/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {

	// your code here

	// Loop through each string in the strings array
	for (int i = 0; i < data->lines; i++) {
		// Check if the current string contains the substring
		if (strstr(data->strings[i], substr) != NULL) {
			// If it does, print the string
			printf("%s\n", data->strings[i]);
		}
	}

}
