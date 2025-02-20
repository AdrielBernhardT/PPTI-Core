#include <stdio.h>
#include <string.h>

struct database {
    char ID[15];
    char name[25];
} mhs [1005];

void merge(int l, int m, int r){
    int sizeL = m - l + 1;
    int sizeR = r - m;
    struct database R[sizeR], L[sizeL];

    for (int i = 0; i < sizeL; i++)
    {
        L[i] = mhs[l + i];
    }

    for (int i = 0; i < sizeR; i++)
    {
        R[i] = mhs[m+1+i];
    }

    int indexL = 0, indexR = 0, indexUtama = l;

    while (indexL < sizeL && indexR < sizeR) {
        if (strcmp (L[indexL].ID , R[indexR].ID) < 0) {
            mhs[indexUtama] = L[indexL];
            indexL++;
        } else {
            mhs[indexUtama] = R[indexR];
            indexR++;
        }
        indexUtama++;
    }

    while (indexL < sizeL)
    {
        mhs[indexUtama] = L[indexL];
        indexL++;
        indexUtama++;
    }

    while (indexR < sizeR)
    {
        mhs[indexUtama] = R[indexR];
        indexR++;
        indexUtama++;
    }
}

void mergeSort(int start, int end){
    if (start < end) {
        int mid =  start + (end - start)/2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);

        merge(start, mid, end);
    }
}

int main(){
    FILE* db =  fopen("testdata.in", "r");
    int tc;
    fscanf(db, "%d", &tc);
    for (int i = 0; i < tc; i++) {
        fscanf(db, "%s %[^\n]\n", mhs[i].ID, mhs[i].name);
    }
    fclose(db);

    mergeSort(0, tc-1);

    for (int i = 0; i < tc; i++) {
        printf("%s %s\n", mhs[i].ID, mhs[i].name);
    }
    return 0;
}