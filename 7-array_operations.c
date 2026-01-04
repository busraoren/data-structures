#include <stdio.h>

#define MAX_SIZE 100

// Function to print the array elements
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. Insertion: Adds an element at a specific index
// Requires shifting elements to the right
void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    // Shift elements to the right to make space
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++; // Increase the size of the array
}

// 2. Deletion: Removes an element from a specific index
// Requires shifting elements to the left
void deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Error: Array is empty!\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Error: Invalid position!\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease the size of the array
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original ");
    printArray(arr, size);

    // Insert 25 at index 2
    printf("Inserting 25 at index 2...\n");
    insertElement(arr, &size, 25, 2);
    printArray(arr, size);

    // Delete element at index 4
    printf("Deleting element at index 4...\n");
    deleteElement(arr, &size, 4);
    printArray(arr, size);

    return 0;
}