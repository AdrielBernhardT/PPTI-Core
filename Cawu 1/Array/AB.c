#include <stdio.h>

#define MAX_N 50

void multiplyMatrices(int N, int A[MAX_N][MAX_N], int B[MAX_N][MAX_N], int result[MAX_N][MAX_N]) {
    int temp[MAX_N][MAX_N] = {0};

    // Multiply A and B, store in temp
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Copy temp to result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

void readMatrix(int N, int matrix[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int N, int matrix[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matrix[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int A[MAX_N][MAX_N], B[MAX_N][MAX_N], C[MAX_N][MAX_N];
        int result[MAX_N][MAX_N];

        readMatrix(N, A);
        readMatrix(N, B);
        readMatrix(N, C);

        multiplyMatrices(N, A, B, result);
        multiplyMatrices(N, result, C, result);

        printf("Case #%d:\n", t);
        printMatrix(N, result);
    }

    return 0;
}