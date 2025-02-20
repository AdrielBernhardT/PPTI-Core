#include <stdio.h>
int main(){
    int tc, n, angka, sum=0;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++)
    {
        scanf("%d", &n);
        for (int ii = 0; ii < n; ii++)
        {
            scanf("%d", &angka);
            sum+=angka;
        }
        printf("Case #%d: %d\n", i, sum);
        sum=0;
    }
    return 0;
}