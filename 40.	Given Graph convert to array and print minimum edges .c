#include <stdio.h>

#define V 5 // Number of vertices

// Function to find the minimum number of edges to visit all vertices
int minEdges(int graph[V][V], int source) {
    int visited[V];
    int count = 0;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int current = source;
    visited[current] = 1;

    while (count < V - 1) {
        int minDist = -1;
        int nextVertex = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[current][i] > 0 && (minDist == -1 || graph[current][i] < minDist)) {
                minDist = graph[current][i];
                nextVertex = i;
            }
        }

        if (nextVertex != -1) {
            visited[nextVertex] = 1;
            current = nextVertex;
            count++;
        } else {
            break; // No more unvisited vertices with edges
        }
    }

    return count;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 4, 5, 7},
        {0, 4, 0, 3, 0},
        {1, 5, 3, 0, 6},
        {0, 7, 0, 6, 0}
    };

    int source = 0; // Source vertex

    int minEdgeCount = minEdges(graph, source);
    printf("Minimum number of edges to visit all vertices: %d\n", minEdgeCount);

    return 0;
}
