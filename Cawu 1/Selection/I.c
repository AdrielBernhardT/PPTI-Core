#include <stdio.h>

int main(){
    int TC;
    long long int price, percent, max, cashback;
    scanf("%d", &TC);
    for (int kasus = 1; kasus <= TC; kasus++)
    {
        scanf("%lld %lld %lld", &price, &percent, &max); getchar();
        cashback = ((price*percent)/100);
        if (cashback > max)
        {
            printf("Case #%d: %lld\n", kasus, max);
        }
        else
        {
            printf("Case #%d: %lld\n", kasus, cashback);
        }
    }
    
    return 0;
}