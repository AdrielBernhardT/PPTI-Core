#include <stdio.h>

int arr[1005] = { [0 ... 1004] = -1 };

int fib(int n){
    if (arr[n] != -1) {
        return arr[n];
    }
    if (n == 0) {
        return 0;
    } 
    if (n == 1 || n == 2) {
        return 1;
    }
    return arr[n] = fib(n - 1) + fib(n - 3);
}

int main(){
    int n;
    scanf("%d", &n);
    int hasil = fib(n);
    printf("%d\n", hasil);
    return 0;
}