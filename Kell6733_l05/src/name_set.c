/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
	// Allocate memory to the data structure
	name_set *set = malloc(sizeof *set);
	// Initialize the header fields.
	set->front = NULL;
	set->rear = NULL;
	return set;
}

int name_set_free(name_set **set) {

	// your code here
	int count = 0;
	// Free the nodes and the set itself
	while ((*set)->front != NULL) {
		name_set_node *temp = (*set)->front;
		(*set)->front = (*set)->front->next;
		free(temp);
		count++;
	}

	*set = NULL;

	return count;

}

BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {

	// your code here

}

BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {

	// your code here
	//set new current node to the front of the list
	name_set_node *current = set->front;

	while (current != NULL) {
		if (strcmp(current->first_name, first_name) == 0
				&& strcmp(current->last_name, last_name) == 0) {
			return TRUE;
		}
		current = current->next;
	}

	return FALSE;

}

void name_set_print(const name_set *set) {

	// your code here

}
