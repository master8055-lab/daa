#include <stdio.h>

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

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].value);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(arr, n);

    float totalValue = 0.0f;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}

