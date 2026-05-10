#include <stdio.h>

#define MAX 100

static int graph[MAX][MAX];
static int indegree[MAX];
static int queue[MAX], front = 0, rear = -1;

static void enqueue(int x) { queue[++rear] = x; }
static int dequeueQ() { return queue[front++]; }
static int isEmpty() { return front > rear; }

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            if (graph[j][i] == 1) indegree[i]++;
        }
    }

    front = 0; rear = -1;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) enqueue(i);
    }

    printf("Topological Order: ");

    int count = 0;

    while (!isEmpty()) {
        int v = dequeueQ();
        printf("%d ", v);
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) enqueue(i);
            }
        }
    }

    if (count != V) {
        printf("\nGraph is not a DAG (cycle exists)\n");
    }

    printf("Time complexity (Adjacency matrix): O(V^2)\n");
    return 0;
}

