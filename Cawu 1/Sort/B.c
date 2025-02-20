#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DataBase {
    int num;
    char name[100];
};

/*
Step:
    Mergesort:
    1. Buat fungsi Mergesort -> menerima arr, index start, index akhir
    2. buat kondisi rekursi if index kiri lebih kecil dari index kanan
    3. cari index tengah arr
    4. lakukan pemanggilan rekursi mergesort untuk kiri, kanan, dan panggil function merge
    Merge:
    1. buat function merge yang meminta arr, index start,index mid, index finish
    2. buat size kiri dan kanan (sizeL, sizeR) didapat dari mengurangi index finish dengan start
    3. declare arr temp kanan kiri untuk menampung urutan (L[sizeL] dan R[sizeR])
    4. masukan data dari arr ke temp kiri dan kanan
    5. buat index penghitung untuk kiri, kanan, dan index arr yang masuk
    6. while ukuran index kiri lebih kecil dari sizeL dan index kanan lebih kecil dari sizeR
    7. if arr kiri index kiri lebih besar/kecil dari arr kanan index kanan
    8. set arr besar(awal) sesuai dengan yang memenuhi kondisi
    9. increment index yang telah di masukan
    10. pastikan ga ada sisa dengan while index kanan/kiri lebih kecil dari size kanan/kiri lakukan hal yang sama ketika memasukan ke arr besar

    Fungsi merger() digunakan untuk menggabungkan dua subarray termasuk menjalankan mergesort bagi kiri maupun kanan
    Fungsi mergeSort() digunakan untuk mengimplementasikan rekursi MergeSort
*/
void merge (struct DataBase DB[], int l, int m, int r) {
    int sizeL = m - l + 1;
    int sizeR = r - m;

    struct DataBase *L = (struct DataBase*)malloc(sizeL*sizeof(struct DataBase));
    struct DataBase *R = (struct DataBase*)malloc(sizeR*sizeof(struct DataBase));


    for (int i = 0; i < sizeL; i++) {
        L[i] = DB[l+i];
    }

    for (int i = 0; i < sizeR; i++) {
        R[i] = DB[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < sizeL && j < sizeR) {
        if (strcmp(L[i].name, R[j].name) < 0) {
            DB[k] = L[i];
            i++;
        } else {
            DB[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < sizeL) {
        DB[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeR) {
        DB[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(struct DataBase DB[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(DB, l, m);
        mergesort(DB, m + 1, r);

        merge(DB, l, m, r);
    }
}

int main(){
    struct DataBase *DB = (struct DataBase*)malloc(1000005*sizeof(struct DataBase));
    FILE* db = fopen("testdata.in", "r");
    int tc;
    fscanf(db, "%d\n", &tc);
    for (int i = 0; i < tc; i++) {
        fscanf(db, "%d#%[^\n]\n", &DB[i].num, &DB[i].name);
    }

    mergesort(DB, 0, tc-1);

    for (int i = 0; i < tc; i++) {
        printf("%d %s\n", DB[i].num, DB[i].name);
    }
    fclose(db);

    return 0;
}