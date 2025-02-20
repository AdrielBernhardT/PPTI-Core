#include <stdio.h>
#include <string.h>

struct database{
    char matkul[15];
    long long int nilai;
} db[105];

void merge(int l, int m, int r){
    int sizeL = m - l + 1, sizeR = r - m;

    struct database L[sizeL], R[sizeR];

    for (int i = 0; i < sizeL; i++) {
        L[i] = db[l + i];
    }

    for (int i = 0; i < sizeR; i++) {
        R[i] = db[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < sizeL && j < sizeR) {
        if (L[i].nilai < R[j].nilai) {
            db[k] = L[i];
            i++;
        } else if (L[i].nilai == R[j].nilai){
            if(strcmp(L[i].matkul, R[j].matkul) < 0){
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

    while (i < sizeL) {
        db[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeR) {
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
    int tc;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%s %lld", db[i].matkul, &db[i].nilai);
    }

    mergesort(0, tc - 1);

    for (int i = 0; i < tc; i++) {
        printf("%s\n", db[i].matkul);
    }
    return 0;
}