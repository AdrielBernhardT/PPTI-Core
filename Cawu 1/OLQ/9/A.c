#include <stdio.h>
#include <string.h>

struct dataBase {
    char nama[55];
    int num;
} db[105];

void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    struct dataBase L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = db[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = db[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].num > R[j].num) {
            db[k] = L[i];
            i++;
        }  else if (L[i].num == R[j].num) {
            if (strcmp(L[i].nama, R[j].nama) < 0) {
                db[k] = L[i];
                i++;
            } else {
                db[k] = R[j];
                j++;
            }
        } else {
            db[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        db[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        db[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int main(){
    int tc, N;
    scanf("%d", &tc); getchar();
    for (int i = 1; i <= tc; i++) {
        scanf("%d", &N); getchar();

        for (int j = 0; j < N; j++) {
            scanf("%[^#]#%d", db[j].nama, &db[j].num); getchar();
        }

        mergesort(0, N - 1);

        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            printf("%s - %d\n", db[j].nama, db[j].num);
        }
    }
    return 0;
}