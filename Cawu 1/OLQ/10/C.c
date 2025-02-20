#include <stdio.h>
#include <string.h>

int binarySearch(char arr[][30], int l, int r, char *x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = strcmp(arr[m], x);
        if (res == 0) return 1;
        if (res < 0) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main(){
    long long int tc;
    char nama[10005][30];
    char cari[30];
    scanf("%lld", &tc);
    for (long long int i = 0; i < tc; i++){
        scanf("%s", nama[i]);
    }

    scanf("%s", cari);

    if (binarySearch(nama, 0, tc - 1, cari)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    
    return 0;
}