#include <stdio.h>
int main(){
    double hasil, persen;
    scanf("%lf %lf", &hasil, &persen); getchar();
    for (int i = 1; i <= 3; i++)
    {
        hasil += (hasil*persen)/100;
    }
    printf("%.2lf\n", hasil);
    return 0;
    
}