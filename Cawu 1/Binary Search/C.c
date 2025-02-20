#include <stdio.h>

int binarysearch(long long int arr[], long long int size, long long int target){
    long long int left = 0, right = size-1;
    long long int firstPos = -1;
    while(left <= right){
        long long int mid = left + (right - left) / 2;
        if (arr[mid] < target){
            left = mid + 1;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            firstPos = mid + 1;
            right = mid - 1;
        }
    }
    return firstPos;
}

void merge(long long int arr[], int l, int m, int r){
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
    while(i < sizel && j < sizer){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < sizel){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < sizer){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(long long int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int N,tc, sum;
    long long a[100005], b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%lld", &a[i]);
    }
    mergesort(a, 0, N-1);
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++){
        scanf("%lld", &b);
        int temp = binarysearch(a, N, b);
        for (int j = 0; i < temp; j++){
            sum+=a[j];
        }
        printf("Case #%d: %d\n", i, sum);
        sum = 0;
    }
    
    return 0;
}