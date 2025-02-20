#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        long long int N, M;
        scanf("%lld %lld", &N, &M);

        long long int *weights = (long long int *)malloc(N * M * sizeof(long long int));
        for (int i = 0; i < N * M; i++) {
            scanf("%lld", &weights[i]);
        }

        long long int totalMaxWeight = 0;
        for (int i = 0; i < N; i++) {
            long long int maxChildWeight = 0;
            for (int j = 0; j < M; j++) {
                long long int weight = weights[i * M + j];
                if (weight > maxChildWeight) {
                    maxChildWeight = weight;
                }
            }
            totalMaxWeight += maxChildWeight;
        }

        printf("Case #%d: %lld\n", t, totalMaxWeight);
        free(weights);
    }

    return 0;
}