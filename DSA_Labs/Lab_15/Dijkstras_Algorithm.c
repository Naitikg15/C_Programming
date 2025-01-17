#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using an adjacency matrix
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX]; // The output array. dist[i] will hold the shortest distance from src to i
    int sptSet[MAX]; // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, n);
}

int main() {
    int graph[MAX][MAX], n, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("\nShortest paths from source vertex %d:\n", src);
    dijkstra(graph, src, n);

    return 0;
}
