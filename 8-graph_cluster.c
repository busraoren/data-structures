#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

// Adjacency Matrix representation of the graph
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int numNodes;

// Depth First Search to visit all nodes in a cluster
void findCluster(int u) {
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < numNodes; v++) {
        // If there is an edge and the neighbor hasn't been visited
        if (graph[u][v] == 1 && !visited[v]) {
            findCluster(v);
        }
    }
}

// Function to extract and print all clusters in the graph
void extractClusters() {
    int clusterCount = 0;

    // Initialize all nodes as not visited
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    printf("Starting Cluster Extraction:\n");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            findCluster(i);
            printf("}\n");
        }
    }
    printf("\nTotal clusters found: %d\n", clusterCount);
}

int main() {
    // Example: A graph with 6 nodes
    numNodes = 6;

    // Initializing graph with 0s
    for(int i=0; i<numNodes; i++)
        for(int j=0; j<numNodes; j++)
            graph[i][j] = 0;

    // Cluster 1: Nodes 0, 1, 2
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;

    // Cluster 2: Nodes 3, 4
    graph[3][4] = graph[4][3] = 1;

    // Node 5 is isolated (Cluster 3)

    extractClusters();

    return 0;
}