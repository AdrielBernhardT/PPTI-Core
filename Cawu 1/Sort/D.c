#include <stdio.h>

struct playlist{
    char title[1005];
    char artist[1005];
    int viewers;
} music[105];

void merge(int l, int m, int r){
    int sizeL = m - l + 1;
    int sizeR = r - m;

    struct playlist L[sizeL], R[sizeR];

    for(int i = 0; i < sizeL; i++){
        L[i] = music[l+i];
    }

    for(int i = 0; i < sizeR; i++){
        R[i] = music[m+1+i];
    }

    int idxL = 0, idxR = 0, idx = l;

    while(idxL < sizeL && idxR < sizeR){
        if(L[idxL].viewers > R[idxR].viewers){
            music[idx] = L[idxL];
            idxL++;
        } else {
            music[idx] = R[idxR];
            idxR++;
        }
        idx++;
    }

    while(idxL < sizeL){
        music[idx] = L[idxL];
        idxL++;
        idx++;
    }

    while(idxR < sizeR){
        music[idx] = R[idxR];
        idxR++;
        idx++;
    }
}

void mergesort(int l, int r){
    if(l < r){
        int m = l + (r - l)/2;
        mergesort(l, m);
        mergesort(m+1, r);

        merge(l, m, r);
    }
}

int main(){
    FILE* db = fopen ("testdata.in", "r");
    int counter = 0;
    while (!feof(db))
    {
        fscanf(db, "%[^#]#%[^#]#%d\n", music[counter].title, music[counter].artist, &music[counter].viewers);
        counter++;
    }

    mergesort(0, counter-1);

    for (int i = 0; i < counter; i++)
    {
        printf("%s by %s - %d\n", music[i].title, music[i].artist, music[i].viewers);
    }
    return 0;
}