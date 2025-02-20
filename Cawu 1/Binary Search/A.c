#include <stdio.h>
#include <stdlib.h>

long long int binarysearch(long long int arr[], long long int size, long long int target){
    long long int left = 0, right = size-1;
    long long int firstPos = -1;
    while(left <= right){
        long long int mid = left + (right - left) / 2;
        if (arr[mid] < target){
            left = mid + 1;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            firstPos = mid + 1;
            right = mid - 1;
        }
    }
    return firstPos;
}

int main(){
    long long N, M;
    long long int *a, *b;
    scanf("%lld %lld", &N, &M);
    a = (long long int*)malloc(N * sizeof(long long int));
    b = (long long int*)malloc(M * sizeof(long long int));
    for (long long int i = 0; i < N; i++){
        scanf("%lld", &a[i]);
    }
    for (long long int i = 0; i < M; i++){
        scanf("%lld", &b[i]);
    }
    // mergesort(a, 0, N-1);
    for (long long int i = 0; i < M; i++){
        long long int temp = binarysearch(a, N, b[i]);
        printf("%lld\n", temp);
    }
    free(a);
    free(b);
    return 0;
}