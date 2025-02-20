#include <stdio.h>
int main(){
    long int kasus, hasil = 1;
    scanf("%ld", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        hasil*=2;
    }
    printf("%ld\n", hasil-1);
    return 0;
}