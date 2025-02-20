#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome using recursion
bool isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        char S[1001];
        scanf("%s", S);
        int len = strlen(S);
        if (isPalindrome(S, 0, len - 1)) {
            printf("Case #%d: yes\n", i);
        } else {
            printf("Case #%d: no\n", i);
        }
    }
    return 0;
}