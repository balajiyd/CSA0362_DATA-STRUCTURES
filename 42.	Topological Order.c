#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6 // Number of vertices

struct Graph {
    int *adjList[V];
};

// Function to create a new graph
struct Graph *createGraph() {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform DFS and store topological order
void DFS(struct Graph *graph, int vertex, bool visited[], int stack[], int *stackIndex) {
    visited[vertex] = true;

    struct Node *temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }

    stack[*stackIndex] = vertex;
    (*stackIndex)++;
}

// Function to find and print topological order
void topologicalSort(struct Graph *graph) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int stack[V];
    int stackIndex = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Order: ");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    struct Graph *graph = createGraph();
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
