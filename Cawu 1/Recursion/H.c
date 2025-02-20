#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

void generateFiboString(char *result, int n, char s0, char s1) {
    if (n == 0) {
        result[0] = s0;
        result[1] = '\0';
        return;
    }
    if (n == 1) {
        result[0] = s1;
        result[1] = '\0';
        return;
    }

    char prev1[MAX_LEN], prev2[MAX_LEN];
    generateFiboString(prev1, n - 1, s0, s1);
    generateFiboString(prev2, n - 2, s0, s1);

    strcpy(result, prev1);
    strcat(result, prev2);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int n;
        char s0, s1;
        scanf("%d %c %c", &n, &s0, &s1);

        char result[MAX_LEN] = {0};
        generateFiboString(result, n, s0, s1);

        printf("Case #%d: %s\n", i, result);
    }

    return 0;
}