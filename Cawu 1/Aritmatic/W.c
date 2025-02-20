#include <stdio.h>
int main(){
    int angka;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &angka);
        angka%=100;
        angka/=10;
        printf("%d\n", angka);
    }
    return 0;
}