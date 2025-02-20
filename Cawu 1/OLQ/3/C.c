#include <stdio.h>
int main(){
    long int angka, j = 1;
    scanf("%d", &angka);
    for (long int i = 0; j <= angka; i++, j++){
        if (i+j == angka){
            printf("%ld = %ld + %ld\n", angka, i, j);
            break;
        }
    }
    return 0;
}