#include <stdio.h>

/*
Step:
    Mergesort:
    1. Buat fungsi Mergesort -> menerima arr, index start, index akhir
    2. buat kondisi rekursi if index kiri lebih kecil dari index kanan
    3. cari index tengah arr
    4. lakukan pemanggilan rekursi mergesort untuk kiri, kanan, dan panggil function merge
    Merge:
    1. buat function merge yang meminta arr, index start, index finish
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

void merge(long long int arr[], int indexL,int indexM, int indexR){
    int sizeL = indexM - indexL + 1;
    int sizeR = indexR - indexM;

    int arrL[sizeL], arrR[sizeR];

    for (int i = 0; i < sizeL; i++)
    {
        arrL[i] = arr[indexL+i];
    }

    for (int i = 0; i < sizeR; i++)
    {
        arrR[i] = arr[indexM + 1 + i];
    }

    int L = 0, R = 0, indexArr = indexL;

    while (L < sizeL && R < sizeR) {
        if (arrL[L] <= arrR[R]) {
            arr[indexArr] = arrL[L];
            L++;
        } else {
            arr[indexArr] = arrR[R];
            R++;
        }
        indexArr++;
    }

    while (L < sizeL) {
        arr[indexArr] = arrL[L];
        L++;
        indexArr++;
    }

    while (R < sizeR) {
        arr[indexArr] = arrR[R];
        R++;
        indexArr++;
    }
}

void mergesort(long long int arr[], int indexL, int indexR){
    if (indexL < indexR) {
        int indexM = indexL + (indexR - indexL) / 2;

        mergesort(arr, indexL, indexM);
        mergesort(arr, indexM + 1, indexR);

        merge(arr, indexL, indexM, indexR);
    }
}

long long int angka[1000005];
long long arr[1000005];

int main() {
    long long int tc;
    scanf("%lld", &tc); getchar();
    for (long long int i = 0; i < tc; i++) {
        scanf("%lld", &angka[i]);  getchar();
    }

    mergesort(angka, 0, tc-1); // udah urut

    int highest = 0;
    for (long long int i = 1; i < tc; i++)
    {
        if (angka[i] - angka[i-1] > highest) {
            highest = angka[i] - angka[i-1];
        }
    }
    long long int counter = 0;
    for (long long int i = 1; i < tc; i++)
    {
        if (angka[i] - angka[i-1] == highest) {
            arr[counter] = angka[i-1];
            arr[counter+1] = angka[i];
            counter+=2;
        }
    }

    for (long long int i = 0; i < counter-1; i++)
    {
        if (!counter-1)
        {
            printf("%lld ", arr[i]);
        }
    }
    printf("%lld\n", arr[counter-1]);

    return 0;
}