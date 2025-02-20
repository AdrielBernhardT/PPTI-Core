#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int i = 0; i < T; i++) {
        char S[100005];
        scanf("%s", S); getchar();
        int len = strlen(S);

        int result = 0;
        for (int j = 0; j < len; j++) {
            result += ((pow (-1, j) * (S[j] - 48)));
        }
        printf("Case #%d: %s\n", i + 1, (result % 11 == 0) ? "Yeah" : "Nah");
    }

    return 0;
}