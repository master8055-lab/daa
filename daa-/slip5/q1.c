#include <stdio.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

static struct Edge edges[MAX];
static int parent[MAX];

static int find_set(int i) {
    while (parent[i] != i) i = parent[i];
    return i;
}

static void union_set(int u, int v) {
    int u_root = find_set(u);
    int v_root = find_set(v);
    parent[u_root] = v_root;
}

static void sortEdges(int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    for (int i = 0; i < V; i++) parent[i] = i;

    sortEdges(E);

    int count = 0;
    int i = 0;
    int total_cost = 0;

    printf("\nEdges in MST:\n");
    while (count < V - 1 && i < E) {
        int u = edges[i].u;
        int v = edges[i].v;
        int set_u = find_set(u);
        int set_v = find_set(v);

        if (set_u != set_v) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            total_cost += edges[i].weight;
            union_set(set_u, set_v);
            count++;
        }
        i++;
    }

    printf("Total cost of MST = %d\n", total_cost);
    return 0;
}

