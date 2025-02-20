#include <stdio.h>
int main(){
    double L,B,H, Luas;
    scanf("%lf %lf %lf", &L, &B, &H); getchar();
    Luas = (2*(H*(B/2)))+(3*L*B);
    printf("%.3lf\n", Luas);

    return 0;
}