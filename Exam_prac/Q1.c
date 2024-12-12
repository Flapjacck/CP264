/*
 -------------------------------------
 File:    Q1.c
 Project: Exam_Prep_Questions
 file description
 -------------------------------------
 Author:  Spencer Kelly
 ID:      169066733
 Email:   Kell6733@mylaurier.ca
 Version  2024-12-11
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a singly linked list node
typedef struct SinglyNode {
	int value;
	struct SinglyNode *next;
} SinglyNode;

// Function to create a new singly linked list node
SinglyNode* createSinglyNode(int value) {
	SinglyNode *newNode = (SinglyNode*) malloc(sizeof(SinglyNode));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

// Function to search for an element in a singly linked list
int searchSingly(SinglyNode *head, int value) {
	int position = 1;
	SinglyNode *current = head;
	while (current != NULL) {
		if (current->value == value) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1; // Element not found
}

// Function to insert an element at a specified position in a singly linked list
void insertSingly(SinglyNode **head, int value, int position) {
	SinglyNode *newNode = createSinglyNode(value);
	if (position == 1) { // Insert at the beginning
		newNode->next = *head;
		*head = newNode;
		return;
	}

	SinglyNode *current = *head;
	for (int i = 1; i < position - 1 && current != NULL; i++) {
		current = current->next;
	}

	if (current == NULL) {
		printf("Invalid position.\n");
		free(newNode);
		return;
	}

	newNode->next = current->next;
	current->next = newNode;
}

// Function to delete an element at a specified position in a singly linked list
void deleteSingly(SinglyNode **head, int position) {
	if (*head == NULL) {
		printf("List is empty.\n");
		return;
	}

	SinglyNode *temp = *head;
	if (position == 1) { // Delete the first node
		*head = temp->next;
		free(temp);
		return;
	}

	for (int i = 1; i < position - 1 && temp != NULL; i++) {
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL) {
		printf("Invalid position.\n");
		return;
	}

	SinglyNode *toDelete = temp->next;
	temp->next = toDelete->next;
	free(toDelete);
}

// Function to display a singly linked list
void displaySingly(SinglyNode *head) {
	while (head != NULL) {
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

////////////////////////////////////////////////////

// Define the structure of a doubly linked list node
typedef struct DoublyNode {
	int value;
	struct DoublyNode *prev;
	struct DoublyNode *next;
} DoublyNode;

// Function to create a new doubly linked list node
DoublyNode* createDoublyNode(int value) {
	DoublyNode *newNode = (DoublyNode*) malloc(sizeof(DoublyNode));
	newNode->value = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

// Function to search for an element in a doubly linked list
int searchDoubly(DoublyNode *head, int value) {
	int position = 1;
	DoublyNode *current = head;
	while (current != NULL) {
		if (current->value == value) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1; // Element not found
}

// Function to insert an element at a specified position in a doubly linked list
void insertDoubly(DoublyNode **head, int value, int position) {
	DoublyNode *newNode = createDoublyNode(value);
	if (position == 1) { // Insert at the beginning
		newNode->next = *head;
		if (*head != NULL) {
			(*head)->prev = newNode;
		}
		*head = newNode;
		return;
	}

	DoublyNode *current = *head;
	for (int i = 1; i < position - 1 && current != NULL; i++) {
		current = current->next;
	}

	if (current == NULL) {
		printf("Invalid position.\n");
		free(newNode);
		return;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL) {
		current->next->prev = newNode;
	}
	current->next = newNode;
}

// Function to delete an element at a specified position in a doubly linked list
void deleteDoubly(DoublyNode **head, int position) {
	if (*head == NULL) {
		printf("List is empty.\n");
		return;
	}

	DoublyNode *temp = *head;
	if (position == 1) { // Delete the first node
		*head = temp->next;
		if (*head != NULL) {
			(*head)->prev = NULL;
		}
		free(temp);
		return;
	}

	for (int i = 1; i < position && temp != NULL; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Invalid position.\n");
		return;
	}

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}
	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	}
	free(temp);
}

// Function to display a doubly linked list
void displayDoubly(DoublyNode *head) {
	while (head != NULL) {
		printf("%d <-> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

//////////////////////////////////////////

int main() {
	// Singly linked list example
	SinglyNode *singlyHead = NULL;
	insertSingly(&singlyHead, 10, 1);
	insertSingly(&singlyHead, 20, 2);
	insertSingly(&singlyHead, 30, 3);
	printf("Singly Linked List: ");
	displaySingly(singlyHead);
	printf("Search for 20 in Singly Linked List: Position = %d\n",
			searchSingly(singlyHead, 20));
	deleteSingly(&singlyHead, 2);
	printf("After deleting position 2: ");
	displaySingly(singlyHead);

	// Doubly linked list example
	DoublyNode *doublyHead = NULL;
	insertDoubly(&doublyHead, 100, 1);
	insertDoubly(&doublyHead, 200, 2);
	insertDoubly(&doublyHead, 300, 3);
	printf("Doubly Linked List: ");
	displayDoubly(doublyHead);
	printf("Search for 200 in Doubly Linked List: Position = %d\n",
			searchDoubly(doublyHead, 200));
	deleteDoubly(&doublyHead, 2);
	printf("After deleting position 2: ");
	displayDoubly(doublyHead);

	return 0;
}
