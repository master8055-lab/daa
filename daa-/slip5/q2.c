#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

struct MinHeap {
    int size;
    struct Node* array[MAX];
};

static struct Node* newNode(char data, unsigned freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

static void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

static void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

static struct Node* extractMin(struct MinHeap* heap) {
    struct Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}

static void insertHeap(struct MinHeap* heap, struct Node* node) {
    int i = heap->size++;

    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

static struct Node* buildHuffman(char data[], int freq[], int n) {
    struct MinHeap heap;
    heap.size = n;

    for (int i = 0; i < n; i++) {
        heap.array[i] = newNode(data[i], (unsigned)freq[i]);
    }

    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapify(&heap, i);
    }

    while (heap.size > 1) {
        struct Node* left = extractMin(&heap);
        struct Node* right = extractMin(&heap);

        struct Node* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertHeap(&heap, top);
    }

    return extractMin(&heap);
}

static void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &data[i]);
    }

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    struct Node* root = buildHuffman(data, freq, n);

    int arr[MAX], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);

    // Complexity note:
    // Heap build: O(n)
    // n-1 extractions+insertions => O(n log n)
    printf("\nBest-case complexity: O(n log n)\n");
    printf("Worst-case complexity: O(n log n)\n");

    return 0;
}

