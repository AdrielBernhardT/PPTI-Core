#include <stdio.h>

int main() {
    int t, anak, coklat;
    long long int arr[505][505],  max = 0, sum = 0;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        sum = 0;
        scanf("%d %d", &anak, &coklat);
        for (int i = 0; i < anak; i++) {
            for (int j = 0; j < coklat; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }
        for (int i = 0; i < anak; i++) {
            for (int j = 0; j < coklat; j++) {
                if (arr[i][j] > max)
                {
                    max = arr[i][j];
                }
            }
            sum+=max;
            max = 0;
        }
        printf("Case #%d: %lld\n", tc, sum);
    }
    return 0;
}

/*
1
3 4 
2 5 7 5
3 4 1 2 
9 2 9 1
*/