#include <stdio.h>
int main(){
    int A, B, C, D;
    float hasil;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d %d", &A, &B, &C, &D);
        hasil = (2*A)+(2*B)+(2*C)+D;
        printf("%.2f\n", hasil);
    }
    
    return 0;
}