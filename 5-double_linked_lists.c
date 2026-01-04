#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// 1. Traversal: Forward and Backward
void displayList(struct Node* node) {
    struct Node* last;
    printf("Forward Traversal: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Backward Traversal: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

// 2. Insertion: After a specific node (Middle)
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // Set next of new node to next of prev_node
    new_node->next = prev_node->next;

    // Set next of prev_node to new_node
    prev_node->next = new_node;

    // Set prev of new_node to prev_node
    new_node->prev = prev_node;

    // If there is a node after new_node, update its prev pointer
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// 3. Deletion: Remove a specific node
void deleteNode(struct Node** head_ref, struct Node* del_node) {
    if (*head_ref == NULL || del_node == NULL)
        return;

    // If the node to be deleted is the head node
    if (*head_ref == del_node)
        *head_ref = del_node->next;

    // If it's NOT the last node, update the next node's prev pointer
    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    // If it's NOT the first node, update the previous node's next pointer
    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
}

// Helper function to insert at front
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30); // List: 30-20-10

    printf("Initial ");
    displayList(head);

    // Insert 25 after 20 (middle insertion)
    insertAfter(head->next, 25);
    printf("\nAfter inserting 25 after 20:\n");
    displayList(head);

    // Delete node 25
    deleteNode(&head, head->next->next); // head->next->next is 25
    printf("\nAfter deleting node 25:\n");
    displayList(head);

    return 0;
}