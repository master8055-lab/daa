#include <stdio.h>

#define MAX 100

static int queue[MAX], front = 0, rear = -1;
static int visited[MAX];

static void enqueue(int v) {
    queue[++rear] = v;
}

static int dequeue() {
    return queue[front++];
}

static int isEmpty() {
    return front > rear;
}

static void BFS(int graph[MAX][MAX], int V, int start) {
    enqueue(start);
    visited[start] = 1;

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
}

int main() {
    int V, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < V; i++) visited[i] = 0;
    front = 0; rear = -1;

    printf("BFS Traversal: ");
    BFS(graph, V, start);
    printf("\n");

    printf("Time complexity (Adjacency matrix): O(V^2)\n");
    return 0;
}

