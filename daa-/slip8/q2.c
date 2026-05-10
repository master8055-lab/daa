#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int visited[MAX] = {0};
    int path[MAX];
    int totalCost = 0;

    int current = 0;
    visited[current] = 1;
    path[0] = current;

    printf("\nPath: %d", current);

    for (int count = 1; count < n; count++) {
        int next = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[current][i] != 0 && cost[current][i] < min) {
                min = cost[current][i];
                next = i;
            }
        }

        if (next != -1) {
            visited[next] = 1;
            path[count] = next;
            totalCost += min;
            current = next;
            printf(" -> %d", next);
        }
    }

    totalCost += cost[current][0];
    printf(" -> %d", 0);

    printf("\nTotal Cost = %d\n", totalCost);
    return 0;
}

