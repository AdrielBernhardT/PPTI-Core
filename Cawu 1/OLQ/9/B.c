#include <stdio.h>
#include <string.h>

void merge(char name[1005][55], int l, int m, int r, int typed){
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][55], R[n2][55];
    for (int i = 0; i < n1; i++) {
        strcpy(L[i], name[l + i]);
    }
    for (int i = 0; i < n2; i++) {
        strcpy(R[i], name[m + 1 + i]);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (typed == 0){
            if (strcmp(L[i],R[j]) < 0) {
                strcpy(name[k], L[i]);
                i++;
            } else {
                strcpy(name[k], R[j]);
                j++;
            }
            k++;
        } else {
            if (strcmp(L[i],R[j]) >= 0) {
                strcpy(name[k], L[i]);
                i++;
            } else {
                strcpy(name[k],R[j]);
                j++;
            }
            k++;
        }
    }
    while (i < n1) {
        strcpy(name[k],L[i]);
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(name[k],R[j]);
        j++;
        k++;
    }
}

void mergesort(char name[1005][55], int l, int r, int typed){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(name, l, m, typed);
        mergesort(name, m + 1, r, typed);
        merge(name, l, m, r, typed);
    }
}

int main(){
    int tc, typed;
    char nama[1005][55];
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%s", nama[i]);
    }
    scanf("%d", &typed);

    mergesort(nama, 0, tc-1, typed);

    for (int i = 0; i < tc; i++) {
        printf("%s\n", nama[i]);
    }
    return 0;
}