#include <stdio.h>

int main(){
    int loopbesar;
    scanf("%d", &loopbesar);
    long long int harga, duit, loopkecil, sum = 0;
    for (int i = 1; i <= loopbesar; i++)
    {
        scanf("%lld %lld", &loopkecil, &duit);
        for (int j = 0; j < loopkecil; j++)
        {
            scanf("%lld", &harga);
            sum += harga;
        }
        if (sum > duit)
        {
            printf("Case #%d: Wash dishes\n", i);
        } 
        else 
        {
            printf("Case #%d: No worries\n", i);
        }
        sum = 0;
    }
    return 0;
}