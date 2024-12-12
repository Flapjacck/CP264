
#include <stdio.h>

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