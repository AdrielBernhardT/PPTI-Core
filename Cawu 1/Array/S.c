#include <stdio.h>
#include <string.h>

void addWithoutCarry(char *a, char *b, char *result) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0;

    for (int i = 0; i < maxLen; i++) {
        int digitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
        int digitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
        int sum = (digitA + digitB) % 10;
        result[maxLen - 1 - i] = sum + '0';
    }
    result[maxLen] = '\0';

    // Remove leading zeros
    int start = 0;
    while (start < maxLen && result[start] == '0') {
        start++;
    }
    if (start == maxLen) {
        // If all characters are zero, keep one zero
        result[0] = '0';
        result[1] = '\0';
    } else {
        // Shift the result to remove leading zeros
        memmove(result, result + start, maxLen - start + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char A[101], B[101], result[102];
        scanf("%s %s", A, B);
        addWithoutCarry(A, B, result);
        printf("Case #%d: %s\n", t, result);
    }
    return 0;
}