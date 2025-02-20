#include <stdio.h>

int fibo(int n){
    if (n == 0 || n == 1) {
        return n;
    }
    if (n%3 == 0) {
        return 10;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int N;
    scanf("%d", &N); getchar();
    int temp = fibo(N);
    for (int i = 0; i < N; i++)
    {
        if (i == N-1) {
            printf("%d\n", fibo(i));
        } else {
            printf("%d ", fibo(i));
        }
    }
    
    return 0;
}
