#include <stdio.h>
int main(){
    int TC, counter[1005], angka[1005], parameter = 0;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d", &angka[i]);
    }
    for (int i = 1; i < TC; i++)
    {
        if (angka[i]<=angka[i-1])
        {
            counter[parameter] = angka[i-1];
            parameter++;
        }
        if (i == TC-1)
        {
            counter[parameter] = angka[i];
        }
        
    }
    for (int i = 0; i <= parameter; i++)
    {
        if (i < parameter)
        {
            printf("%d ", counter[i]);
        }
        else
        {
            printf("%d\n", counter[i]);
        }
    }
    return 0;
}