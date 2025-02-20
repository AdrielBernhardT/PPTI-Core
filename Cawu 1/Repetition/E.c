#include <stdio.h>

int main() {
    int loop;
    scanf("%d", &loop);
    for (int i = 0; i < loop; i++) {
        int angka, biner;
        scanf("%d %d", &angka, &biner);
        if ((angka >> biner) & 1) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}