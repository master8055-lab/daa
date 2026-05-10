#include <stdio.h>

#define MAX 100

static int graph[MAX][MAX];
static int visited[MAX];
static int queue[MAX], front = 0, rear = -1;

static void enqueue(int v) { queue[++rear] = v; }
static int dequeue() { return queue[front++]; }
static int isEmpty() { return front > rear; }

static void BFS(int V, int start) {
    for (int i = 0; i < V; i++) visited[i] = 0;

    front = 0; rear = -1;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");

    printf("Time complexity (Adjacency matrix): O(V^2) for both BFS/DFS\n");
}

static void DFS(int V, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(V, i);
        }
    }
}

int main() {
    int V, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) scanf("%d", &graph[i][j]);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(V, start);

    for (int i = 0; i < V; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(V, start);
    printf("\n");

    return 0;
}

