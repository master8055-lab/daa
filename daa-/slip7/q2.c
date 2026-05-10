#include <stdio.h>

#define MAX 100

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    int count = 0;
    int topo[MAX];

    while (front <= rear) {
        int u = queue[front++];
        topo[count++] = u;

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[++rear] = v;
            }
        }
    }

    if (count != V) {
        printf("Graph is not a DAG (cycle exists)\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}

