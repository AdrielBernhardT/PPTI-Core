#include <stdio.h>
int main(){
    int TC;
    double a,b,c,d, hasil;

    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        hasil = (2*a)+(2*b)+(4*(c/3))+(d/2);
        printf("%.2lf\n", hasil);
    }
    return 0;
}