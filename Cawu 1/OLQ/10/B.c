#include <stdio.h>
#include <string.h>

int binarySearch(char words[][101], int left, int right, char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(words[mid], target);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    char words[N][101];
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    char F[101];
    scanf("%s", F);

    int index = binarySearch(words, 0, N - 1, F);
    int page;
    
    if (index == -1) {
        page = 0;
    } else {
        page = (index / X) + 1;
    }

    printf("%d\n", page);

    return 0;
}

/*
10
3
am
encouraged
equally
expanded
got
inquiry
lots
passed
successful
tea
expanded
*/