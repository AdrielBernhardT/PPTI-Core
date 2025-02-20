#include <stdio.h>
int main(){
    int loop;
    scanf("%d", &loop);
    long long int male[loop], female[loop];
    for (int i = 1; i <= loop; i++)
    {
        scanf("%lld %lld", &male[i], &female[i]);
    }
    for (int i = 1; i <= loop; i++)
    {
        if ((male[i]*female[i])%2==0)
        {
            printf("Case #%d: Party time!\n", i);
        }   else {
            printf("Case #%d: Need more frogs\n", i);
        }
    }
    return 0;
}