#include <stdio.h>
int main(){
    long int angka, poin = 1;
    scanf("%ld", &angka);
    for (long int i = 2; i < angka+2; i++){
        poin += i;
    }
    printf("%ld\n", poin);
    return 0;
}