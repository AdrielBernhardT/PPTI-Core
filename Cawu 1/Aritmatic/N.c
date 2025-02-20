#include <stdio.h>
int main(){
    double modal, akhir, diskon;
    scanf("%lf %lf", &modal, &akhir);
    diskon = akhir * 100/modal;
    diskon = 100-diskon;
    printf("%.2lf%%\n", diskon);
    return 0;
}