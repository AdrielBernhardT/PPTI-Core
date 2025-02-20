#include <stdio.h>
#include <stdlib.h>

struct base {
    char name[1005];
    int makanan;
    int price;
    int sum;
} datas[1005];

void bubblesort(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (datas[j].sum < datas[j + 1].sum) {
                struct base temp = datas[j];
                datas[j] = datas[j + 1];
                datas[j + 1] = temp;
            }
        }
    }
}

void merge(int l, int m, int r) {
    int sizel = m - l + 1;
    int sizer = r - m;
    struct base *left = (struct base *)malloc(sizel * sizeof(struct base));
    struct base *right = (struct base *)malloc(sizer * sizeof(struct base));
    
    for (int i = 0; i < sizel; i++) {
        left[i] = datas[l + i];
    }
    for (int i = 0; i < sizer; i++) {
        right[i] = datas[m + 1 + i];
    }
    
    int i = 0, j = 0, k = l;
    while (i < sizel && j < sizer) {
        if (left[i].sum >= right[j].sum) {
            datas[k] = left[i];
            i++;
        } else {
            datas[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < sizel) {
        datas[k] = left[i];
        i++;
        k++;
    }
    while (j < sizer) {
        datas[k] = right[j];
        j++;
        k++;
    }
    
    free(left);
    free(right);
}

void mergesort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++) {
        scanf("%s %d %d", datas[i].name, &datas[i].makanan, &datas[i].price);
    }
    for (int i = 1; i <= tc; i++) {
        datas[i].sum = datas[i].makanan * datas[i].price;
    }
    
    // mergesort(1, tc);
    bubblesort(tc);

    for (int i = 1; i <= tc; i++) {
        printf("%s %d\n", datas[i].name, datas[i].sum);
    }
    
    return 0;
}