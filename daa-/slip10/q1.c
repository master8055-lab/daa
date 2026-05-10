#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

static struct Node* newNode(char data, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

static void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

static void heapify(struct Node* heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left]->freq < heap[smallest]->freq) smallest = left;
    if (right < size && heap[right]->freq < heap[smallest]->freq) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

static struct Node* extractMin(struct Node* heap[], int *size) {
    struct Node* temp = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return temp;
}

static void insertHeap(struct Node* heap[], int *size, struct Node* node) {
    int i = (*size)++;
    while (i && node->freq < heap[(i - 1) / 2]->freq) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = node;
}

static struct Node* buildHuffman(char data[], int freq[], int n) {
    struct Node* heap[MAX];
    int size = n;

    for (int i = 0; i < n; i++) heap[i] = newNode(data[i], freq[i]);

    for (int i = (size - 2) / 2; i >= 0; i--) heapify(heap, size, i);

    while (size > 1) {
        struct Node* left = extractMin(heap, &size);
        struct Node* right = extractMin(heap, &size);

        struct Node* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertHeap(heap, &size, top);
    }

    return heap[0];
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
    for (int i = 0; i < n; i++) scanf(" %c", &data[i]);

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++) scanf("%d", &freq[i]);

    struct Node* root = buildHuffman(data, freq, n);

    int arr[MAX], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);
    return 0;
}

