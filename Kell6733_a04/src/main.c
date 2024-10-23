/**
 * -------------------------------------
 * @file  main.c
 * file description
 * -------------------------------------
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "stack_dynamic.h"
#include "queue_dynamic.h"
#include "pq_dynamic.h"
#include "list_dynamic.h"

#define SEP "-------------------------------------\n"

void test_stack_generic(data_type values[], int count) {
	data_type item;

	stack_dynamic_struct *source = NULL;
	stack_initialize(&source, STACK_INIT);

	printf("Testing stack_dynamic\n");
	printf(SEP);
	printf("stack_empty: %s\n", BOOL_TO_STR(stack_empty(source)));
	printf(SEP);
	printf("stack_push\n");

	for (int i = 0; i < count; i++) {
		printf("push: ");
		data_print(&values[i]);
		printf("\n");
		stack_push(source, &values[i]);
	}
	for (int i = 0; i < count; i++) {
		printf("push: ");
		data_print(&values[i]);
		printf("\n");
		stack_push(source, &values[i]);
	}
	printf(SEP);
	printf("stack_empty: %s\n", BOOL_TO_STR(stack_empty(source)));
	printf(SEP);
	printf("stack_peek\n");
	stack_peek(source, &item);
	printf("item: ");
	data_print(&item);
	printf("\n");
	printf(SEP);
	printf("stack_print\n");
	stack_print(source);
	printf(SEP);
	printf("stack_pop\n");

	while (!stack_empty(source)) {
		stack_pop(source, &item);
		printf("popped: ");
		data_print(&item);
		printf("\n");
	}
}

void test_queue_generic(data_type values[], int count) {
	data_type item;

	// Initialize the queue
	queue_dynamic_struct *source = NULL;
	queue_initialize(&source, QUEUE_INIT);

	printf("Testing queue_dynamic\n");
	printf(SEP);
	printf("queue_empty: %s\n", BOOL_TO_STR(queue_empty(source)));
	printf(SEP);
	printf("queue_insert\n");

	// Enqueue all values
	for (int i = 0; i < count; i++) {
		printf("Insert: ");
		data_print(&values[i]);
		printf("\n");
		queue_insert(source, &values[i]);
	}
	printf(SEP);
	printf("queue_empty: %s\n", BOOL_TO_STR(queue_empty(source)));
	printf(SEP);
	printf("queue_peek\n");

	// Peek at the front item
	queue_peek(source, &item);
	printf("item: ");
	data_print(&item);
	printf("\n");
	printf(SEP);
	printf("queue_print\n");

	// Print the queue
	queue_print(source);
	printf(SEP);
	printf("queue_remove\n");

	// Dequeue all items
	while (!queue_empty(source)) {
		queue_remove(source, &item);
		printf("removed: ");
		data_print(&item);
		printf("\n");
	}
}

void test_pq_generic(data_type values[], int count) {
	data_type item;

	// Initialize the priority queue
	pq_dynamic_struct *source = NULL;
	pq_initialize(&source, PQ_INIT);

	printf("Testing pq_dynamic\n");
	printf(SEP);
	printf("pq_empty: %s\n", BOOL_TO_STR(pq_empty(source)));
	printf(SEP);
	printf("pq_insert\n");

	// Enqueue all values
	for (int i = 0; i < count; i++) {
		printf("insert: ");
		data_print(&values[i]);
		printf("\n");
		pq_insert(source, &values[i]);
	}
	printf(SEP);
	printf("pq_empty: %s\n", BOOL_TO_STR(pq_empty(source)));
	printf(SEP);
	printf("pq_peek\n");

	// Peek at the highest priority item
	pq_peek(source, &item);
	printf("item: ");
	data_print(&item);
	printf("\n");
	printf(SEP);
	printf("pq_print\n");

	// Print the priority queue
	pq_print(source);
	printf(SEP);
	printf("pq_remove\n");

	// Dequeue all items
	while (!pq_empty(source)) {
		pq_remove(source, &item);
		printf("dequeued: ");
		data_print(&item);
		printf("\n");
	}
}

void test_list_generic(data_type values[], int count) {
	data_type item;

	// Initialize the list
	list_dynamic_struct *source = NULL;
	list_initialize(&source, LIST_INIT);

	printf("Testing list_dynamic\n");
	printf(SEP);
	printf("list_empty: %s\n", BOOL_TO_STR(list_empty(source)));
	printf(SEP);
	printf("list_insert\n");

	// Insert all values
	for (int i = 0; i < count; i++) {
		printf("insert: ");
		data_print(&values[i]);
		printf("\n");
		list_append(source, &values[i]);
	}
	printf(SEP);
	printf("list_empty: %s\n", BOOL_TO_STR(list_empty(source)));
	printf(SEP);
	printf("list_peek\n");

	// Peek at the first item
	list_peek(source, &item);
	printf("item: ");
	data_print(&item);
	printf("\n");
	printf(SEP);
	printf("list_print\n");

	// Print the list
	list_print(source);
	printf(SEP);
	printf("list_remove\n");

	// Remove all items
	while (!list_empty(source)) {
		list_index_remove(source, &item, 0);
		printf("removed: ");
		data_print(&item);
		printf("\n");
	}
}

void test_stack_int() {
	// Test the stack with integer data.
	data_type values[] = { 2, 4, 1, 7, 4, 2, 9 };
	const int COUNT = sizeof values / sizeof *values;
	test_stack_generic(values, COUNT);
}

void test_queue_int() {
	// Test the queue with integer data.
	data_type values[] = { 2, 4, 1, 7, 4, 2, 9 };
	const int COUNT = sizeof values / sizeof *values;
	test_queue_generic(values, COUNT);
}

void test_pq_int() {
	// Test the priority queue with integer data.
	data_type values[] = { 2, 4, 1, 7, 4, 2, 9 };
	const int COUNT = sizeof values / sizeof *values;
	test_pq_generic(values, COUNT);
}

void test_list_int() {
	// Test the list with integer data.
	data_type values[] = { 2, 4, 1, 7, 4, 2, 9 };
	const int COUNT = sizeof values / sizeof *values;
	test_list_generic(values, COUNT);
}

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	printf(SEP);
	test_stack_int();
	printf(SEP);
	test_queue_int();
	printf(SEP);
	test_pq_int();
	printf(SEP);
	test_list_int();
	return (0);
}
