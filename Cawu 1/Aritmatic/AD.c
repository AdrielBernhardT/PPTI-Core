#include <stdio.h>
int main(){
    double A, M, F, H;
    scanf("%lf %lf %lf", &A, &M, &F);
    H = (A*20/100)+(M*30/100)+(F*50/100);
    printf("%.2lf\n", H);

    return 0;
}