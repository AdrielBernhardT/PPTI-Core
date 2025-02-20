#include <stdio.h>

int angka[1005] = {0};
int call_count = 0; // Global counter for function calls

int fibo(int n){
    call_count++; // Increment the counter each time fibo is called
    // if(angka[n] != 0) return angka[n];
    if(n == 0) return 1;
    else if(n == 1) return 2;
    else return angka[n] = fibo(n-1) + fibo(n-2);
}

int main(){
    int T, n;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        call_count = 0; // Reset the counter for each test case
        scanf("%d", &n);
        fibo(n);
        printf("Case #%d: %d\n", i, call_count);
    }
    
    return 0;
}