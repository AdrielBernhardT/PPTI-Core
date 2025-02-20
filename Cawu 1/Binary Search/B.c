#include <stdio.h>

long long sum_of_squares(long long N) {
    return (N * (N + 1) * (2 * N + 1)) / 6;
}

long long find_minimum_N(long long M) {
    long long left = 1, right = 1500000, result = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (sum_of_squares(mid) >= M) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        long long M;
        scanf("%lld", &M);

        long long N = find_minimum_N(M);
        printf("Case #%d: %lld\n", i, N);
    }
    return 0;
}
