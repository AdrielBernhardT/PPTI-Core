#include <stdio.h>

void merge(long long int *arr, int l, int m, int r){
    int sizel = m - l + 1;
    int sizer = r - m;
    int left[sizel], right[sizer];
    for (int i = 0; i < sizel; i++){
        left[i] = arr[l + i];
    }
    for (int i = 0; i < sizer; i++){
        right[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < sizel && j < sizer){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < sizel){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < sizer){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(long long int *arr, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int T, N, highest = 0, temp = 0;
    long long int angka[505];
    scanf("%d", &T); getchar();
    for (int i = 1; i <= T; i++){
        scanf("%d", &N); getchar();
        for (int j = 0; j < N; j++){
            scanf("%lld", &angka[j]); getchar();
        }
        mergeSort(angka, 0, N - 1);

        for (int j = 0, k = j+1; k < N/2; j++, k++){
            temp = angka[j] - angka[k];
            if (temp < 0){
                temp *= -1;
            }
            if (temp > highest){
                highest = temp;
            }
        }
        for (int j = N/2, k = j+1; k < N; j++, k++){
            temp = angka[j] - angka[k];
            if (temp < 0){
                temp *= -1;
            }
            if (temp > highest){
                highest = temp;
            }
        }
        
        printf("Case #%d: %d\n", i, highest);
        highest = 0;
    }
    
    return 0;
}