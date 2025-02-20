#include <stdio.h>

int main(){
    long long int TC, angka, sum = 0;
    scanf("%lld", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%lld", &angka);
        if (angka>0)
        {
            sum+=angka;
        }
    }
    printf("%lld\n", sum);
    return 0;
}