#include <stdio.h>
#include <string.h>
#define MAX 100

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[MAX], Y[MAX];

    printf("Enter first string: ");
    scanf("%99s", X);

    printf("Enter second string: ");
    scanf("%99s", Y);

    int m = (int)strlen(X);
    int n = (int)strlen(Y);

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printf("Length of LCS = %d\n", L[m][n]);
    return 0;
}

