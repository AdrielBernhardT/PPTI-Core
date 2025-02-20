#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int case_num = 1; case_num <= t; case_num++) {
        int n;
        scanf("%d", &n);

        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            long long int num;
            scanf("%lld", &num);
            sum += num;
        }

        printf("Case #%d: %lld\n", case_num, sum);
    }

    return 0;
}
