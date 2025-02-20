#include <stdio.h>
int main(){
    long int A, hasil = 1;
    for (int i = 0; i < 3; i++)
    {
        scanf("%ld", &A);
        hasil*=A;
    }
    printf("%ld\n", hasil);

    return 0;
}