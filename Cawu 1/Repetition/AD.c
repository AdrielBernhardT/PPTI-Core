#include <stdio.h>

int main(){
    int TC, angka, data[1005] = {0}, max = 0;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d", &angka);
        data[angka]++;
    }
    
    for (int i = 0; i <= 1000; i++)
    {
        if (data[i] != 0)
        {
            if (data[i] > max)
            {
                max = data[i];
            }
        }
    }
    printf("%d\n", max);
    
    return 0;
}