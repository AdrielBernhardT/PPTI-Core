#include <stdio.h>
int main(){
    long long int attack, damage, maxAtt = 0, maxDmg = 0, tempAtt, tempDmg;
    scanf("%lld %lld", &tempAtt, &tempDmg);
    for (int i = 0; i < tempAtt; i++)
    {
        scanf("%lld", &attack);
        if (maxAtt<attack)
        {
            maxAtt=attack;
        }
    }
    for (int i = 0; i < tempDmg; i++)
    {
        scanf("%lld", &damage);
        if (maxDmg<damage)
        {
            maxDmg=damage;
        }
    }
    if (maxAtt > maxDmg)
    {
        printf("The dark secret was true\n");
    }
    else
    {
        printf("Secret debunked\n");
    }
    return 0;
}