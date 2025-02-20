#include <stdio.h>
int main(){
    double r = 0,c = 0,f = 0,k = 0;
    int TC;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++)
    {
        scanf("%lf", &c); getchar();
        r = (4*c)/5;
        f = ((9*c)/5)+32;
        k = c + 273;
        printf("%.2lf %.2lf %.2lf\n", r, f, k);
    }
    return 0;
}