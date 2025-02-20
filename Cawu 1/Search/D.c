#include <stdio.h>
#include <string.h>

struct rank{
    char name[15];
    int score;
} rank [1005];

void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    struct rank L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = rank[l + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = rank[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i].score > R[j].score){
            rank[k] = L[i];
            i++;
        } else if (L[i].score == R[j].score){
            if (L[i].name < R[j].name){
                rank[k] = L[i];
                i++;
            } else {
                rank[k] = R[j];
                j++;
            }
        } else {
            rank[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        rank[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        rank[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int main(){
    int tc, N;
    char carinama[15];
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++){
        scanf("%d", &N);  getchar();
        for (int j = 0; j < N; j++){
            scanf("%[^#]#%d", rank[j].name, &rank[j].score); getchar();
        }
        scanf("%s", carinama); getchar();
        mergesort(0, N - 1);
        for (int j = 0; j < N; j++){
            if (strcmp(rank[j].name, carinama) == 0){
                printf("Case #%d: %d\n", i+1, j + 1);
                break;
            }
        }
    }
    return 0;
}

/*
2
3
Jojo#40
Lili#80
Bibi#90 
Lili 
3 
Jojo#100
Lili#80
Bibi#90
Lili
*/