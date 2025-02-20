#include <stdio.h>

int main() {
    int loop; // jumlah testcase
    scanf("%d", &loop);

    for (int case_num = 1; case_num <= loop; case_num++) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);

        int piring[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &piring[i]);
            if (piring[i] <= M && piring[i] > K) {
                K = piring[i];
            }
        }
        printf("Case #%d: %d\n", case_num, K);
    }
    return 0;
}