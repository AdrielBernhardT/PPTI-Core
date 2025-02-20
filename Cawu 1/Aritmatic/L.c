#include <stdio.h>
int main(){
   long long int price, money, parameter = 0;
   scanf("%lld %lld", &price, &money);
   while (price >= money)
   {
        price-=money;
        parameter++;
   }
   printf("%lld\n", parameter);
    return 0;
    
}