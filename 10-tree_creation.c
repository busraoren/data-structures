#include <stdio.h>

#define MAX_NODES 15 // Array size for a tree of height 4

int tree[MAX_NODES];

// Initialize the tree with -1 to represent empty nodes
void initializeTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = -1;
    }
}

// Set the root node
void setRoot(int key) {
    tree[0] = key;
}

// Set left child of a parent at given index
void setLeft(int key, int parentIndex) {
    int leftChildIndex = (2 * parentIndex) + 1;
    
    if (tree[parentIndex] == -1) {
        printf("Error: Cannot set child. Parent at index %d does not exist.\n", parentIndex);
    } else if (leftChildIndex >= MAX_NODES) {
        printf("Error: Index out of bounds.\n");
    } else {
        tree[leftChildIndex] = key;
    }
}

// Set right child of a parent at given index
void setRight(int key, int parentIndex) {
    int rightChildIndex = (2 * parentIndex) + 2;
    
    if (tree[parentIndex] == -1) {
        printf("Error: Cannot set child. Parent at index %d does not exist.\n", parentIndex);
    } else if (rightChildIndex >= MAX_NODES) {
        printf("Error: Index out of bounds.\n");
    } else {
        tree[rightChildIndex] = key;
    }
}

// Function to print the tree array
void printTree() {
    printf("Tree Array Representation: ");
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
        else
            printf("- "); // Represents empty spot
    }
    printf("\n");
}

int main() {
    initializeTree();

    setRoot(10);           // Root (Index 0)
    setLeft(20, 0);        // Left of 10 (Index 1)
    setRight(30, 0);       // Right of 10 (Index 2)
    setLeft(40, 1);        // Left of 20 (Index 3)
    setRight(50, 1);       // Right of 20 (Index 4)
    setRight(60, 2);       // Right of 30 (Index 6)

    printTree();

    return 0;
}