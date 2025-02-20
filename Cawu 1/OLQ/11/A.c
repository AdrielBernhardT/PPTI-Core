#include <stdio.h>
#include <string.h>

void merge(char name[105][25], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][25], R[n2][25];
    for (int i = 0; i < n1; i++){
        strcpy(L[i], name[l + i]);
    }
    for (int i = 0; i < n2; i++){
        strcpy(R[i], name[m + 1 + i]);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (strcmp(L[i], R[j]) <= 0){
            strcpy(name[k], L[i]);
            i++;
        } else {
            strcpy(name[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < n1){
        strcpy(name[k], L[i]);
        i++;
        k++;
    }
    while (j < n2){
        strcpy(name[k], R[j]);
        j++;
        k++;
    }
}

void mergesort(char name[105][25], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(name, l, m);
        mergesort(name, m + 1, r);
        merge(name, l, m, r);
    }
}

int search(char name[105][25], int l, int r, char target[25]){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (strcmp(name[mid], target) == 0){
            return mid;
        }
        if (strcmp(name[mid], target) > 0){
            return search(name, l, mid - 1, target);
        }
        return search(name, mid + 1, r, target);
    }
    return -1;
}

int linearsearch(char name[105][25], int l, int r, char target[25]){
    for (int i = l; i <= r; i++){
        if (strcmp(name[i], target) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    FILE *db = fopen("testdata.in", "r");
    int N, M;
    char name[105][25];
    char target[25];
    fscanf(db, "%d", &N);
    for (int i = 0; i < N; i++){
        fscanf(db, "%s", name[i]);
    }
    fscanf(db, "%d", &M);

    // mergesort(name, 0, N-1);

    for (int i = 0; i < M; i++){
        fscanf(db, "%s", target);
        int result = linearsearch(name, 0, N-1, target);
        printf("%d\n", result);      
    }
    fclose(db);
    return 0;
}