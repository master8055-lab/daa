#include <stdio.h>

#define MAX 20

static int board[MAX][MAX];
static int N;

static int isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return 0;

    return 1;
}

static int solve(int row) {
    if (row == N) return 1;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solve(row + 1)) return 1;
            board[row][col] = 0;
        }
    }

    return 0;
}

static void printSolution() {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter value of N: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solve(0)) printSolution();
    else printf("No solution exists\n");

    return 0;
}

