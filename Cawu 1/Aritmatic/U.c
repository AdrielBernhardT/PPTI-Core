#include <stdio.h>
int main(){
    int TC;
    double A, B, hasil;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%lf %lf", &A, &B);
        hasil = (A*B)/360;
        printf("%.2lf\n", hasil);
    }
    return 0;
}