#include <stdio.h>
int main(){
    long long int angka1, angka2, sum = 0;
    scanf("%lld %lld", &angka1, &angka2);
    for (int i = angka1; i <= angka2; i++)
    {
        sum+=i;
    }
    
    printf("%lld\n", sum);

    return 0;
}