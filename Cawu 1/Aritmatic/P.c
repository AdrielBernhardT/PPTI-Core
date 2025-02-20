#include <stdio.h>

int main(){
    double akhir, diskon, modal;
    for (int i = 0; i < 4; i++)
    {
        scanf("%lf %lf", &diskon, &akhir);
        modal = (akhir*100)/(100-diskon);
        printf("$%.2lf\n", modal);
    }
    return 0;
}