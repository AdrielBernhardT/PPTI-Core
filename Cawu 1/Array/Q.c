#include <stdio.h>

void toggle_lights(int rooms[], int pattern[], int M) {
    for (int i = 0; i < M; i++) {
        if (pattern[i] == 1) {
            rooms[i] = !rooms[i];
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M, Q;
        scanf("%d %d %d", &N, &M, &Q);

        int patterns[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &patterns[i][j]);
            }
        }

        int rooms[M];
        for (int i = 0; i < M; i++) {
            rooms[i] = 0; // All lights are initially off
        }

        for (int i = 0; i < Q; i++) {
            int friend;
            scanf("%d", &friend);
            toggle_lights(rooms, patterns[friend - 1], M);
        }

        printf("Case #%d:\n", t);
        for (int i = 0; i < M; i++) {
            if (rooms[i] == 1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}