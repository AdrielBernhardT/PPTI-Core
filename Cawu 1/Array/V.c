#include <stdio.h>

long long int arr[95] = {0,1};
long long int fibbo(int n){
    if (arr[n] != 0)
    {
        return arr[n];
    }
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return arr[n] = fibbo(n-1) + fibbo(n-2);;
}

int main(){
    int Tc;
    long long int n;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", i, fibbo(n-1)); 
    }
    
    return 0;
}