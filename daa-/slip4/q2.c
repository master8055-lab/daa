#include <stdio.h>

struct Item {
    int value, weight;
    float ratio;
};

static void sortByRatio(struct Item arr[], int n) {
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
    int n;
    int capacity;

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

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    sortByRatio(arr, n);

    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            total += arr[i].value;
        } else {
            total += arr[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value = %.2f\n", total);
    return 0;
}

