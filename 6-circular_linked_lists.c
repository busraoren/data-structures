#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Linked List
struct Node {
    int data;
    struct Node* next;
};

// 1. Traversal: Printing the circular list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        printf("Circular List: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head); // Stop when we return to the head
        printf("(Head again)\n");
    } else {
        printf("List is empty.\n");
    }
}

// 2. Insertion: Adding a node after a given node (Middle)
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // Standard insertion logic
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// 3. Deletion: Removing a node with a specific key
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *curr = *head_ref, *prev;

    // Case 1: If the head node itself holds the key
    if (curr->data == key) {
        // If there's only one node in the list
        if (curr->next == *head_ref) {
            free(curr);
            *head_ref = NULL;
            return;
        }
        
        // Find the last node to update its next pointer
        prev = *head_ref;
        while (prev->next != *head_ref) {
            prev = prev->next;
        }
        prev->next = curr->next;
        *head_ref = curr->next;
        free(curr);
        return;
    }

    // Case 2: Search for the node to be deleted
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If node was found
    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Key %d not found in the list.\n", key);
    }
}

// Helper function to insert at front to build the list
void insertAtFront(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
    } else {
        new_node->next = new_node; // Self-loop for the first node
    }
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;

    // Creating initial list: 30 -> 20 -> 10
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);

    printf("Initial ");
    printList(head);

    // Insert 25 after 20 (middle insertion)
    insertAfter(head->next, 25);
    printf("After inserting 25 after 20:\n");
    printList(head);

    // Delete node 10
    printf("Deleting node 10...\n");
    deleteNode(&head, 10);
    printList(head);

    return 0;
}