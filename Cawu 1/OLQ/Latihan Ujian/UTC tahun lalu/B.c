#include <stdio.h>

int main(){
    int tc, persen, angka[1005], temp, sum = 0;
    scanf("%d %d", &tc, &persen);
    for (int i = 1; i <= tc; i++)
    {
        scanf("%d", &angka[i]);
        sum+=angka[i];
    }
    // printf("%d\n", sum);
    temp = (sum*persen)/(100*tc);
    // printf("%d\n", temp);
    sum = 0;
    for (int i = 1;  i <= tc; i++, sum++)
    {
        if (angka[i] > temp)
        {
            break;
        }
        temp-=angka[i];
    }
    // printf("%d\n", sum);
    sum = tc-sum+1;
    // printf("%d\n", sum);
    if (sum == tc){
        printf("0\n");
    }
    else
    {
        for (int i = sum; i <= tc; i++)
        {
            if (i == tc)
            {
                printf("%d\n", i);
            }
            else
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    
    return 0;
}