# Question 5 Break Down

## Heapify-Up MAX

- The function `heapifyUpMax` is used to maintain the max heap property after inserting an element into the heap.
- The function takes two parameters:
    - `heap[]`: The array representing the heap.
    - `index`: The index of the element that needs to be heapified.
- The function compares the element at the given index with its parent node.
- If the element is greater than its parent, the function swaps the element with its parent and continues this process until the heap property is satisfied.
- The function stops when the element is less than or equal to its parent or when the element reaches the root of the heap.

```c
void heapifyUpMax(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2; // Parent node index
        
        // If the current node is greater than its parent, swap them
        if (heap[index] > heap[parent]) {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            
            index = parent; // Move up to the parent index
        } else {
            break; // If the heap property is satisfied, stop
        }
    }
}
```

## Heapify-Up MIN

- The function `heapifyUpMin` is used to maintain the min heap property after inserting an element into the heap.
- The function takes two parameters:
    - `heap[]`: The array representing the heap.
    - `index`: The index of the element that needs to be heapified.
- The function compares the element at the given index with its parent node.
- If the element is less than its parent, the function swaps the element with its parent and continues this process until the heap property is satisfied.
- The function stops when the element is greater than or equal to its parent or when the element reaches the root of the heap.

```c
void heapifyUpMin(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2; // Parent node index
        
        // If the current node is less than its parent, swap them
        if (heap[index] < heap[parent]) {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            
            index = parent; // Move up to the parent index
        } else {
            break; // If the heap property is satisfied, stop
        }
    }
}
```

## Main File

```c
int main() {
    // Example max-heap
    int maxHeap[10] = {50, 30, 20, 15, 10, 8, 16};
    int sizeMax = 7;

    // Insert a new element into the max-heap
    maxHeap[sizeMax] = 40; // New element
    heapifyUpMax(maxHeap, sizeMax);
    sizeMax++;

    printf("Max-Heap after insertion: ");
    for (int i = 0; i < sizeMax; i++) {
        printf("%d ", maxHeap[i]);
    }
    printf("\n");

    // Example min-heap
    int minHeap[10] = {10, 15, 20, 30, 25, 50, 40};
    int sizeMin = 7;

    // Insert a new element into the min-heap
    minHeap[sizeMin] = 5; // New element
    heapifyUpMin(minHeap, sizeMin);
    sizeMin++;

    printf("Min-Heap after insertion: ");
    for (int i = 0; i < sizeMin; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");

    return 0;
}
```