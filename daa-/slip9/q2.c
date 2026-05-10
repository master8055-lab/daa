#include <stdio.h>

#define MAX 50

static int w[MAX], x[MAX];
static int n, target;

static void printSubset() {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) printf("%d ", w[i]);
    }
    printf("}\n");
}

static void sumOfSubsets(int k, int currentSum, int remainingSum) {
    x[k] = 1;

    if (currentSum + w[k] == target) {
        printSubset();
    } else if (currentSum + w[k] + remainingSum >= target && k + 1 < n) {
        sumOfSubsets(k + 1, currentSum + w[k], remainingSum - w[k]);
    }

    if (currentSum + remainingSum - w[k] >= target && k + 1 < n) {
        x[k] = 0;
        sumOfSubsets(k + 1, currentSum, remainingSum - w[k]);
    }
}

int main() {
    int total = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum = %d:\n", target);
    sumOfSubsets(0, 0, total);

    return 0;
}

