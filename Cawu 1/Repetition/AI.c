#include <stdio.h>

int main() {
    int TC;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++) {
        int n;
        scanf("%d", &n);

        int array[n], sum = 0, tabungan = 0;

        for (int j = 0; j < n; j++) {
            scanf("%d", &array[j]);
            sum += array[j];
        }

        if (sum % 2 != 0) {
            printf("Case #%d: No\n", i);
            continue;
        }

        for (int j = 0; j < n; j++) {
            tabungan += array[j];
            if (tabungan == (sum / 2)) {
                printf("Case #%d: Yes\n", i);
                break;
            }
        }
        if (tabungan != (sum / 2))
        printf("Case #%d: No\n", i);
    }
    return 0;
}