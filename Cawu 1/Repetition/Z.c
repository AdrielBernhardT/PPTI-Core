#include <stdio.h>
int main(){
    int angka, sum = 0, TC;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d", &angka);
        sum+=angka;
        if (sum == 12)
        {
            sum = 28;
        }
        else if (sum == 30)
        {
            sum = 10;
        }
        else if (sum == 35)
        {
            sum = 7;
        }    
        else if (sum >= 40)
        {
            sum-=40;
        }
            
    }
    printf("%d\n", sum);
    
    return 0;
}