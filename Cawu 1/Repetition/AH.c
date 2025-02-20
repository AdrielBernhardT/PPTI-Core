#include <stdio.h>
int main(){
    long long int TC, angka, counter=0;
    scanf("%lld", &TC);
    for (int i = 1; i <= TC; i++)
    {
        scanf("%lld", &angka);
        while (angka > 0)
        {
            angka/=10;
            counter++;
        }
        printf("Case #%d: %lld\n", i, counter);
        counter = 0;
    }
    return 0;
}