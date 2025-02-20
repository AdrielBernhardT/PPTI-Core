#include <stdio.h>
int main(){
    int TC;
    double A,B;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%lf %lf", &A, &B);
        B*=(A/100);
        printf("%.2lf\n", B);
    }
    

    return 0;
}