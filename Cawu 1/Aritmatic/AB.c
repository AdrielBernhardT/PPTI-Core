#include <stdio.h>
int main(){
    long int round, base = 100, damage = 50, hasil = 0;
    scanf("%ld", &round);
    for (int i = 0; i < round; i++)
    {
       hasil += base + (damage*i);
    }
    printf("%ld\n", hasil);

    return 0;
}