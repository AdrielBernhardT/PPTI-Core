#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int count[N + 1];
    for (int i = 0; i <= N; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);
            if (num != 0) {
                count[num]++;
            }
        }
    }

    int incomplete_teams = 0;
    for (int i = 1; i <= N; i++) {
        if (count[i] < N) {
            incomplete_teams++;
        }
    }

    printf("%d\n", incomplete_teams);

    return 0;
}