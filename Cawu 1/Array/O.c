#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N][N];
    // Input matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Check rows for duplicates
    for (int i = 0; i < N; i++) {
        int row_check[N + 1];
        for (int k = 0; k <= N; k++) row_check[k] = 0;
        for (int j = 0; j < N; j++) {
            if (row_check[arr[i][j]] == 1) {
                printf("Nay\n");
                return 0;
            }
            row_check[arr[i][j]] = 1;
        }
    }

    // Check columns for duplicates
    for (int j = 0; j < N; j++) {
        int col_check[N + 1];
        for (int k = 0; k <= N; k++) col_check[k] = 0;
        for (int i = 0; i < N; i++) {
            if (col_check[arr[i][j]] == 1) {
                printf("Nay\n");
                return 0;
            }
            col_check[arr[i][j]] = 1;
        }
    }

    printf("Yay\n");
    return 0;
}