#include <stdio.h>
#include <limits.h>

#define MAX 50

static int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

static int optimalBST(int keys[], int freq[], int n) {
    int cost[MAX][MAX];

    for (int i = 0; i < n; i++) cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter keys:\n");
    for (int i = 0; i < n; i++) scanf("%d", &keys[i]);

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++) scanf("%d", &freq[i]);

    int cost = optimalBST(keys, freq, n);
    printf("Cost of Optimal BST = %d\n", cost);
    return 0;
}

