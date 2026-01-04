#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a Max Heap
struct MaxHeap {
    int arr[MAX_SIZE];
    int size;
};

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Max-Heapify: Maintains the heap property at index i
void maxHeapify(struct MaxHeap *h, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        maxHeapify(h, largest);
    }
}

// 2. Insertion: Adds a new value to the heap
void insert(struct MaxHeap *h, int value) {
    if (h->size == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    // Insert the new key at the end
    int i = h->size;
    h->arr[i] = value;
    h->size++;

    // Fix the max heap property: Move the value up (Percolate Up)
    while (i != 0 && h->arr[(i - 1) / 2] < h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 3. Extract Max: Removes and returns the maximum element (root)
int extractMax(struct MaxHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1]; // Move last element to root
    h->size--;
    maxHeapify(h, 0); // Re-heapify from the root

    return root;
}

void printHeap(struct MaxHeap *h) {
    printf("Heap Array: ");
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}

int main() {
    struct MaxHeap h = {.size = 0};

    insert(&h, 10);
    insert(&h, 20);
    insert(&h, 5);
    insert(&h, 30);
    insert(&h, 15);

    printf("After Insertions:\n");
    printHeap(&h);

    printf("Extracted Max: %d\n", extractMax(&h));
    printf("After Extraction:\n");
    printHeap(&h);

    return 0;
}