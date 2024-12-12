# Question 1 Break Down (Linked Lists)

## Search:

### Singly Linked List

- Set position to 1 for the first element
- make a current and set to the head of the list, for traversing the list
- traverse the list until the current is not NULL using a while loop
- check if the value of the current node is equal to the value we are searching for
- if it is, return the position
- if not, move to the next node and increment the position
- if the loop ends, return -1, meaning the element was not found

```c
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
```

### Doubly Linked List

- Same as the singly linked list

```c
// Function to search for an element in a doubly linked list
int searchDoubly(DoublyNode *head, int value) {
	int position = 1;
	DoublyNode *current = head;
	while (current != NULL) {
		if (current->value == value) {
			return position;
		}
		current = current->next;
		position++;s
	}
	return -1; // Element not found
}
```

## Insert

### Singly Linked List

- Create a new node with the value to be inserted
- Check if the position is 1, if it is, insert at the beginning
- If not, traverse the list until the position before the position to insert
- Insert the new node at the specified position
- If the position is invalid, print an error message and free the new node

```c
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
```

### Doubly Linked List

- Same as the singly linked list
- The only difference is that we need to set the previous pointer of the new node to the current node and the next pointer of the current node to the new node
- Also, we need to check if the next node is not NULL before setting its previous pointer to the new node
- If the position is invalid, print an error message and free the new node


```c
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
```

## Delete

### Singly Linked List

- Check if the list is empty, print an error message if it is
- If the position is 1, delete the first node
- Traverse the list until the position before the position to delete
- Delete the node at the specified position
- If the position is invalid, print an error message
- Free the node to delete

```c
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
```

### Doubly Linked List

- Same as the singly linked list
- The only difference is that we need to set the previous pointer of the next node to the previous node of the node to delete

```c
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
```