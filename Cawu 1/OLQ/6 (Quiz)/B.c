#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    int min_odd = 100001, arr;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr);
        sum += arr;
        if (arr % 2 != 0 && arr < min_odd) {
            min_odd = arr;
        }
    }

    if (sum % 2 != 0) {
        sum -= min_odd;
    }

    printf("%lld\n", sum);
    return 0;
}