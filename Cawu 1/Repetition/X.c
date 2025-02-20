#include <stdio.h>
int main(){
    long long int angka, sum = 1;
    scanf("%lld", &angka);
    for (int i = 0; i < angka; i++)
    {
        sum = (sum*2)+1;
    }
    
    printf("%lld\n", sum);
    return 0;
}