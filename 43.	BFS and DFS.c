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

// Function to perform Breadth First Search (BFS)
void BFS(struct Graph *graph, int startVertex) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int queue[V];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear] = startVertex;
    rear++;

    printf("BFS: ");

    while (front < rear) {
        int currentVertex = queue[front];
        printf("%d ", currentVertex);
        front++;

        struct Node *temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear] = adjVertex;
                rear++;
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

// Function to perform Depth First Search (DFS)
void DFS(struct Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    struct Graph *graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int startVertex = 0; // Starting vertex for BFS and DFS

    printf("Graph:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        struct Node *temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    BFS(graph, startVertex);
    
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("DFS: ");
    DFS(graph, startVertex, visited);
    printf("\n");

    return 0;
}
