#include <stdio.h>

struct inputan{
    char city[1005];
    float deegree;
    char units;
} db [105];

void merge(int l, int m, int r){
    int sizeL = m - l + 1, sizeR = r - m;

    struct inputan L[sizeL], R[sizeR];

    for (int i = 0; i < sizeL; i++) {
        L[i] = db[l + i];
    }

    for (int i = 0; i < sizeR; i++) {
        R[i] = db[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < sizeL && j < sizeR) {
        if (L[i].deegree < R[j].deegree) {
            db[k] = L[i];
            i++;
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
    FILE* DB = fopen("testdata.in" , "r");
    int count = 0;
    while (!feof(DB)) {
        fscanf(DB, "%[^#]#%f#%c\n", db[count].city, &db[count].deegree, &db[count].units);
        count++;
    }
    fclose(DB);

    for (int i = 0; i < count; i++) {
        if (db[i].units == 'F') {
            db[i].deegree = (db[i].deegree - 32) * 5 / 9;
        }
    }

    mergesort(0, count - 1);

    for (int i = 0; i < count; i++) {
        if (db[i].units == 'F') {
            db[i].deegree = db[i].deegree * 9 / 5 + 32;
        }
        printf("%s is %.2f%c\n", db[i].city, db[i].deegree, db[i].units);
    }
    return 0;
}