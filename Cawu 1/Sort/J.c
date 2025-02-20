#include <stdio.h>

void merge(long long int arr[], int l, int m, int r){
    int sizel = m - l + 1;
    int sizer = r - m;

    long long L[sizel], R[sizer];

    for(int i = 0; i < sizel; i++){
        L[i] = arr[l + i];
    }

    for(int i = 0; i < sizer; i++){
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < sizel && j < sizer){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < sizel){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < sizer){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long long int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    int T, jumlahdata;
    long long sum = 0;
    long double median, mean;
    scanf("%d", &T); getchar();
    for (int i = 1; i <= T; i++){
        scanf("%d", &jumlahdata);
        long long data[5005] = {[0 ... 5004] = 0};
        for (int j = 0; j < jumlahdata; j++){
            scanf("%lld", &data[j]); getchar();
            sum += data[j];
        }
        mergeSort(data, 0, jumlahdata - 1);
        mean = sum / jumlahdata;
        if (jumlahdata % 2 == 0){
            median = (data[jumlahdata / 2] + data[jumlahdata / 2 - 1]) / 2.0;
        } else {
            median = data[jumlahdata / 2];
        }
        printf("Case #%d:\nMean : %.2llf\nMedian : %.2llf\n", i, mean, median);
        sum = 0;
    }
    return 0;
}