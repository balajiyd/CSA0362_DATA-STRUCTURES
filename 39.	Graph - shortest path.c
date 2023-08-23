#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // Number of vertices

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in shortest path
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to vertex
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to print the solution
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t%d ", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

// Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array to store the shortest distance from src to i
    bool sptSet[V]; // A set to keep track of vertices included in shortest path tree
    int parent[V]; // Array to store the parent vertex in shortest path

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 0, 10, 0}
    };

    int source = 0; // Source vertex
    dijkstra(graph, source);

    return 0;
}
