#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int level, profit, weight;
    float bound;
};

struct Item {
    int value, weight;
    float ratio;
};

static void sort(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].ratio < arr[j].ratio) {
                struct Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

static float bound(struct Node u, int n, int W, struct Item arr[]) {
    if (u.weight >= W) return 0;

    float profit_bound = (float)u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while (j < n && totweight + arr[j].weight <= W) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (W - totweight) * arr[j].ratio;
    }

    return profit_bound;
}

static int knapsack(int W, struct Item arr[], int n) {
    struct Node u, v;
    struct Node queue[MAX];
    int front = 0, rear = 0;

    int maxProfit = 0;

    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v, n, W, arr);
    queue[rear++] = v;

    while (front < rear) {
        v = queue[front++];

        if (v.level == n - 1) continue;

        u.level = v.level + 1;

        // Include item
        u.weight = v.weight + arr[u.level].weight;
        u.profit = v.profit + arr[u.level].value;

        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = bound(u, n, W, arr);
        if (u.bound > maxProfit)
            queue[rear++] = u;

        // Exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, arr);
        if (u.bound > maxProfit)
            queue[rear++] = u;
    }

    return maxProfit;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i].value);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    sort(arr, n);

    int result = knapsack(W, arr, n);
    printf("Maximum profit = %d\n", result);

    return 0;
}

