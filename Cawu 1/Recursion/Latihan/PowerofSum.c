#include <stdio.h>
#include <math.h>

int recursive(int target, int power, int sum, int n){
    int p = pow(n, power);
    if (sum + p == target) return 1;
    if (sum + p > target) return 0;
    return recursive(target, power, sum + p, n + 1) + recursive(target, power, sum, n + 1);
}

int main(){
    int X, N;
    scanf("%d %d", &X, &N); getchar();
    printf("%d\n", recursive(X, N, 0, 1));
    return 0;
}