#include <stdio.h>
int main(){
    double modal, akhir, diskon;
    scanf("%lf %lf", &akhir, &modal);
    diskon = akhir * 100/modal;
    printf("%.2lf%%\n", diskon);
    return 0;
}