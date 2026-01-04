#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int adjMatrix[MAX][MAX];
bool visited[MAX];
int n; // Number of nodes

// --- BFS Queue Implementation ---
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// 1. Breadth First Search (BFS)
void BFS(int startNode) {
    for (int i = 0; i < n; i++) visited[i] = false;

    enqueue(startNode);
    visited[startNode] = true;

    printf("BFS Traversal: ");
    while (front <= rear && front != -1) {
        int currNode = dequeue();
        if (currNode == -1) break;
        printf("%d ", currNode);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[currNode][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// 2. Depth First Search (DFS) - Recursive
void DFS(int u) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < n; v++) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    n = 5; // Example: 5 nodes (0 to 4)

    // Initializing matrix with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adjMatrix[i][j] = 0;

    // Adding edges (Undirected Graph)
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[2][4] = adjMatrix[4][2] = 1;

    // Run BFS
    BFS(0);

    // Reset visited for DFS
    for (int i = 0; i < n; i++) visited[i] = false;
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}