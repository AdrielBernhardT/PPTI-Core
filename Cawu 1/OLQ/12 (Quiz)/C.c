#include <stdio.h>
#include <string.h>

void merge(char dict[][55], long long int l, long long int m, long long int r){
    int sizel = m - l + 1;
    int sizer = r - m;
    char left[sizel][55], right[sizer][55];
    for (int i = 0; i < sizel; i++){
        strcpy(left[i], dict[l + i]);
    }
    for (int i = 0; i < sizer; i++){
        strcpy(right[i], dict[m + 1 + i]);
    }
    int i = 0, j = 0, k = l;
    while(i < sizel && j < sizer){
        if(strcmp(left[i], right[j]) <= 0){
            strcpy(dict[k], left[i]);
            i++;
        }else if(strcmp(left[i], right[j]) > 0){
            strcpy(dict[k], right[j]);
            j++;
        }
        k++;
    }
    while(i < sizel){
        strcpy(dict[k], left[i]);
        i++;
        k++;
    }
    while(j < sizer){
        strcpy(dict[k], right[j]);
        j++;
        k++;
    }
}

void mergesort(char dict[][55], long long l, long long r){
    if(l < r){
        long long m = l + (r - l) / 2;
        mergesort(dict, l, m);
        mergesort(dict, m + 1, r);
        merge(dict, l, m, r);
    }
}

int main(){
    long long N, page, indikator = 0, flag = -1;
    char dict[10005][55], searching[55];
    scanf("%lld", &N); getchar();
    for (long long i = 0; i < N; i++){
        scanf("%s", dict[i]); getchar();
    }
    scanf("%lld", &page); getchar();
    scanf("%s", searching); getchar();
    mergesort(dict, 0, N - 1);
    for (long long i = 0; i < N; i++){
        if (i % page == 0){
            indikator++;
        }
        if (strcmp(dict[i], searching) == 0){
            flag = 1;
            break;
        }
    }
    if (flag == -1){
        printf("Not Found\n");
    } else {
        printf("Found at %lld\n", indikator);
    }
    return 0;
}