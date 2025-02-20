#include <stdio.h>
int main(){
    long int angka, poin = 3;
    scanf("%ld", &angka);
    poin*=angka;
    if (angka>2){
        for (long int i = 1; i <= angka-2; i++){
            poin += i;
        }
    }
    printf("%ld\n", poin);
    return 0;
}