#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[MAX][MAX], int n) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX]; // Array to store constructed MST
    int key[MAX];    // Key values used to pick minimum weight edge in cut
    int mstSet[MAX]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;      // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;  // First node is always root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, n);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < n; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, n);
}

int main() {
    int graph[MAX][MAX], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph, n);

    return 0;
}
