#include <stdio.h>

int rekursi(int M, int N){
    if (M == 0){
        return N+1;
    } else if(M > 0 && N == 0){
        return rekursi(M-1, 1);
    } else if(M > 0 && N > 0){
        return rekursi(M-1, rekursi(M, N-1));
    }
}

int main(){
    int N, M, result;
    scanf("%d %d", &M, &N);
    result = rekursi(M, N);
    printf("result: %d\n", result);
    return 0;
}