#include <stdio.h>

#define MAX 10

static int graph[MAX][MAX];
static int visited[MAX];
static int queue[MAX];
static int front = 0, rear = -1;

static void enqueue(int x) { queue[++rear] = x; }
static int dequeue() { return queue[front++]; }
static int isEmpty() { return front > rear; }

int main() {
    int V, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    for (int i = 0; i < V; i++) visited[i] = 0;
    front = 0; rear = -1;

    enqueue(start);
    visited[start] = 1;

    printf("\nTraversal with Node Types:\n");

    while (!isEmpty()) {
        int node = dequeue();
        printf("E-node (Expanding): %d\n", node);

        int isLeaf = 1;

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                printf("Live node: %d\n", i);
                isLeaf = 0;
            }
        }

        if (isLeaf) {
            printf("Dead node: %d\n", node);
        }

        printf("\n");
    }

    return 0;
}

