#include <stdio.h>
int main(){
    long int angka;
    scanf("%ld", &angka);
    if (angka%2 == 0)
    {
        printf("EVEN\n");
    }
    else
    {
        printf("ODD\n");
    }
    return 0;
}