#include <stdio.h>

#define MAX 100

static int visited[MAX];

static void DFS(int graph[MAX][MAX], int V, int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, V, i);
        }
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < V; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, V, start);

    printf("\nTime complexity (Adjacency matrix): O(V^2)\n");
    return 0;
}

