# Question 1 Breakdown

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

```c
```

### Doubly Linked List

```c
```

## Delete

### Singly Linked List

```c
```

### Doubly Linked List

```c
```