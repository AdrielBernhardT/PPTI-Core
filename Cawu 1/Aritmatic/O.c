#include <stdio.h>
int main(){
    long int A, B;
    for (int i = 0; i < 4; i++)
    {
        scanf("%ld %ld", &A, &B);
        printf("%ld\n", A*B);
    }
    return 0;
}